cmake_minimum_required(VERSION 3.24.1)


project(MyLogger LANGUAGES CXX)

add_executable(FileLogger src/main.cpp src/Logger.cpp)

target_compile_features(FileLogger PRIVATE cxx_std_20)
target_compile_options(FileLogger PRIVATE -Wall -Wextra -Werror)
