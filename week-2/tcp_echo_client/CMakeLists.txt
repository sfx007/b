cmake_minimum_required(VERSION 3.22.1)

project(tcp_client LANGUAGES CXX)


add_executable(tcp_client src/main.cpp)


target_compile_features(tcp_client PRIVATE cxx_std_20)
target_compile_options(tcp_client PRIVATE -Wall -Wextra -Werror)