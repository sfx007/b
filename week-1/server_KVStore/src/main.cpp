#include "../include/header.hpp"
#include <string>
#include <iostream>
#include <csignal>
#include <vector>
#include <sstream>


volatile std::sig_atomic_t flag = 0;

void signal_handler(int signal)
{
    (void)signal;
    flag = 1;
}

void parse_input(const std::string& input, std::vector<std::string>& args)
{
    std::istringstream ss(input);
    std::string word;
    while(ss >> word)
    {
        args.push_back(word);
    }
}

int main()
{
    KVStore<int,std::string> kv;
    std::string input;

    while (1)
    {
        std::vector<std::string> args;
        std::optional<std::string> respond;
        std::string cmd;
        int key = 0;
        std::string value;

        if(flag)
            break;
        if(!(std::getline(std::cin, input)))
            break;
        if(flag)
            break;



        parse_input(input,args);
        if(args.empty())
        {
            std::cout << "empty request!" << std::endl;
            continue;
        }
        if(args.size() == 3)
        {
            cmd = args.at(0);
            try{
                key = std::stoi(args.at(1));
            }
            catch (...) {
                std::cout << "Invalid key (must be int)" << std::endl;
                continue;
            }
            value = args.at(2);
        }
        else if (args.size() == 2)
        {
            cmd = args.at(0);
            try{
                key = std::stoi(args.at(1));
            }
            catch (...) {
                std::cout << "Invalid key (must be int)" << std::endl;
                continue;
            }
        }
        else
        {
            std::cout << "Invalid arguments!" << std::endl;
            continue;
        }


        if(cmd == "put")
        {
            if(args.size() == 3)
                kv.put(key, value);
            else
                std::cout << "Invalid arguments!" << std::endl;
        }
        else if (cmd == "remove")
        {
            if(args.size() == 2)
                kv.remove(key);
            else
                std::cout << "Invalid arguments!" << std::endl;
        }
        else if (cmd == "get")
        {
            if(args.size() != 2)
            {
                std::cout << "Invalid arguments!" << std::endl;
                continue;
            }
            respond = kv.get(key);
            if(respond.has_value())
                std::cout << key << ": " << respond.value() << std::endl;
            else
                std::cout << "key not found!" << std::endl;

        }
        else
            std::cout << "unknown request!" << std::endl; 
    }
    std::cout << "Shutting down..." << std::endl;
    return 0;
}