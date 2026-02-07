#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <cctype>
#include <cstddef>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <mutex>

class Logger{

private:
    std::ofstream _file;
    std::string _level;
    static std::mutex mutex;
public:
    void writeMessage(std::string msg);
    Logger(const char *file, const char *level);
    ~Logger(){};
};

#endif
