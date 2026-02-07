#include <iostream>
#include <csignal>
#include <chrono>
#include <thread>

std::sig_atomic_t a = 0;

void print(int signal)
{
    a = 1;
}

int main()
{
    signal(SIGINT, print);
    while(1)
    {
        if (a == 1)
        {
            std::cout << "Shutting down..." << std::endl;
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "thinking..." << std::endl;
    }
    return (0);
}