#include "../include/Logger.hpp"

std::mutex Logger::mutex;

void Logger::writeMessage(std::string msg)
{
    if(_file.is_open())
    {
        std::lock_guard<std::mutex> guard(mutex);
        std::time_t rawtime;
        char buffer[26];
        buffer[25] = '\0';
        std::time(&rawtime);
        std::string time(ctime_r(&rawtime, buffer));
        if(!time.empty() && time.back() == '\n')
        {
            time.pop_back(); // because ctime_r put new_Line by default.
        }
        std::string line = time + " [" + _level + "] " + msg;
        _file << line << std::endl;
    }
}

Logger::Logger(const char *file, const char *level)
{
    _file.open(file, std::ios::app);
    if(_file.fail())
    {
        std::cout << "ERROR open file: " << file << std::endl;
    }
    size_t lent = strlen(level);
    char level_name[lent + 1];
    level_name[lent] = '\0';
    for(size_t i = 0; i < lent; i++)
    {
        char a = static_cast<char>(std::toupper(static_cast<unsigned char>(level[i])));
        level_name[i] = a;
    }
    _level = level_name;
}
