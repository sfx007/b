#include <cstring>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>
#include <cerrno>
#include <arpa/inet.h>
#include <signal.h>
#include "../include/kv_store.hpp"
#include <vector>
#include <pthread.h>

volatile sig_atomic_t flag = 1;

void handler(int sig)
{
    (void)sig;
    flag = 0;
}


void setup_sig()
{
    struct sigaction sa;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = handler;
    sigaction(SIGINT, &sa, nullptr);
    signal(SIGPIPE, SIG_IGN);
}


int recv_line(int fd, std::string& pending, std::string& line)
{
    char buffer[1024];
    size_t pos = pending.find('\n');
    ssize_t n;
    if(pos != std::string::npos)
    {
        line = pending.substr(0, pos);
        if(!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);
        pending = pending.substr(pos+1);
        return 1;
    }
    while(1)
    {
        n = recv(fd, buffer, 1024, 0);
        if(n == 0)
            return 0;
        else if (n == -1)
        {
            if(errno == EINTR)
                continue;
            return -1;
        }
        pending.append(buffer, n);
        pos = pending.find('\n');
        if(pos != std::string::npos)
        {
            line = pending.substr(0, pos);
            if(!line.empty() && line[line.size() - 1] == '\r')
                line.erase(line.size() - 1);
            pending = pending.substr(pos+1);
            break;
        }
    }
    return 1;
}


int send_all(int fd, const std::string& respond)
{
    const char *buffer = respond.c_str();
    ssize_t n;
    int remind = respond.length();
    int index = 0;
    while(remind != 0)
    {
        n = send(fd, &buffer[index], remind, 0);
        if(n == 0)
            return -1;
        else if(n == -1)
        {
            if(errno == EINTR)
                continue;
            return -1;
        }
        remind -= n;
        index += n;
    }
    return 1;
}


std::string handle_request(const std::string& request, KVStore<std::string, std::string>& DataBase)
{
    std::istringstream ss(request);
    std::string word;
    std::vector<std::string>args;
    while(ss >> word)
    {
        args.push_back(word);
    }

    if(args.empty())
    {
        return ""; 
    }
    std::string cmd = args.at(0);
    if(cmd == "SET")
    {
        if(args.size() != 3)
        {
            return "ERR";
        }
        DataBase.put(args.at(1),args.at(2));
    }
    else if(cmd == "GET")
    {
        if(args.size() != 2)
        {
            return "ERR";
        }
        auto res = DataBase.get(args.at(1));
        if(res.has_value())
            return res.value();
        else
            return "NOTFOUND";
    }
    else if (cmd == "DEL")
    {
        if(args.size() != 2)
        {
            return "ERR";
        }
        DataBase.remove(args.at(1));
    }
    else
        return "ERR";
    return "OK";
}

void* client_thread(void* arg)
{
    int n;
    std::string pending;
    std::string request;
    std::string respond;
    size_t commands_count = 0;
    clientInfo_t *info = static_cast<clientInfo_t *>(arg);

    std::cout << "[+] client connected fd=" << info->fd << std::endl;
    while(flag)
    {
        n = recv_line(info->fd,pending ,request);
        if(n == 0)
            break;
        if(n < 0)
        {
            if(errno == EINTR)
            {
                if(!flag)
                    break;
                perror("recv");
                continue;
            }
            perror("recv");
            break;
        }
        pthread_mutex_lock(info->locker);
        respond = handle_request(request, *(info->DataBase));
        pthread_mutex_unlock(info->locker);
        if(respond.empty())
            continue;
        commands_count++;
        respond.push_back('\n');
        if(send_all(info->fd, respond) <= 0)
        {
            perror("send");
            break;
        }
    }
    std::cout << "[-] client disconnected fd=" << info->fd << " total_commands=" << commands_count << std::endl;
    close(info->fd);
    delete info;
    return nullptr;
}

int main()
{
    setup_sig();
    KVStore<std::string, std::string> DataBase;
    pthread_mutex_t locker;
    if (pthread_mutex_init(&locker, NULL) != 0)
    {
        perror("pthread_mutex_init");
        return 1;
    }
    int fd_server = socket(AF_INET, SOCK_STREAM, 0);
    if(fd_server == -1)
    {
        std::cout << "Faild to create socket!" << std::endl;
        return 1;
    }
    int opt = 1;
    if(setsockopt(fd_server, SOL_SOCKET, SO_REUSEADDR, &opt,  sizeof(opt)) == -1)
    {
        perror("setsockopt");
    }

    sockaddr_in server_add;
    std::memset(&server_add, 0, sizeof(server_add));
    server_add.sin_family = AF_INET;
    server_add.sin_port = htons(7070);
    server_add.sin_addr.s_addr =htonl(INADDR_ANY);
    if (bind(fd_server, (struct sockaddr*)&server_add, sizeof(server_add)) == -1)
    {
        perror("bind");
        std::cout << "Faild to bind" << std::endl;
        close(fd_server);
        return 1;
    }
    if (listen(fd_server, 10) == -1)
    {
        std::cout << "Faild to listen" << std::endl;
        close(fd_server);
        return 1;   
    }
    while(flag)
    {
        int fd_client = accept(fd_server, nullptr, nullptr);
        if(fd_client == -1)
        {
            if(errno == EINTR)
                continue;
            std::cout << "faild to accept client" << std::endl;
            break;
        }
        if(!flag)
        {
            close(fd_client);
            break;
        }
        clientInfo_t* ptr = new clientInfo_t;
        ptr->DataBase = &DataBase;
        ptr->fd = fd_client;
        ptr->locker = &locker;

        pthread_t pt;
        if(pthread_create(&pt, NULL, client_thread, ptr) != 0)
        {
            perror("pthread_create");
            delete ptr;
            close(fd_client);
            continue;
        }
        pthread_detach(pt);
    }
    std::cout << "Shutting down..." << std::endl;
    close(fd_server);
    pthread_mutex_destroy(&locker);
}