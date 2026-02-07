#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>



int recv_line(int fd, std::string& pending, std::string& line)
{
    char buffer[2];
    size_t pos = pending.find('\n');
    ssize_t n;
    if(pos != std::string::npos)
    {
        line = pending.substr(0, pos);
        pending = pending.substr(pos+1);
        return 1;
    }
    while(1)
    {
        n = recv(fd, buffer, 2, 0);
        if(n == 0)
            return 0;
        else if (n == -1)
            return -1;
        pending.append(buffer, n);
        pos = pending.find('\n');
        if(pos != std::string::npos)
        {
            line = pending.substr(0, pos);
            pending = pending.substr(pos+1);
            break;
        }
    }
    return 1;
}

int send_all(int fd, const std::string& request)
{
    size_t reminder = request.length();
    ssize_t n;
    const char *s_request = request.c_str();
    size_t index = 0;
    while(reminder != 0)
    {
        n = send(fd, &s_request[index], reminder, 0);
        if(n == -1)
            return -1;
        reminder -= n;
        index += n;
    }
    return 1;
}

int main(int ac, char **av)
{
    if(ac < 2)
    {
        std::cout << "Pass argument, DUMB!!" << std::endl;
        return 1;
    }


    std::string respond;
    std::string pending;
    std::string request = av[1];
    request.push_back('\n');
    sockaddr_in server_add;
    int n;

    if(request.empty())
    {
        std::cout << "empty argument" << std::endl;
        return 1;
    }
    
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0)
    {
        perror("socket");
        return 1;
    }
    std::memset(&server_add, 0, sizeof(server_add));
    server_add.sin_family = AF_INET;
    server_add.sin_port = htons(7070);
    inet_pton(AF_INET, "127.0.0.1", &server_add.sin_addr);
    if (connect(socket_fd, (struct sockaddr *)&server_add, sizeof(server_add)) == -1)
    {
        perror("connect");
        close(socket_fd);
        return 1;
    }
    n = send_all(socket_fd, request);
    if(n == -1)
    {
        perror("send");
        close(socket_fd);
        return 1;
    }
    n = recv_line(socket_fd, pending, respond);
    if(n == 0)
    {
        perror("recv");
        close(socket_fd);
        return 1;
    }
    else if(n == -1)
    {
        perror("recv");
        close(socket_fd);
        return 1;
    } 
    std::cout << respond << std::endl;
    close(socket_fd);
    return 0;
}