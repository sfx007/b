cmake_minimum_required(VERSION 3.22.1)

project(tcp_server LANGUAGES CXX)

add_executable(tcp_server src/main.cpp src/kv_store.tpp)

target_include_directories(tcp_server PRIVATE include)
target_compile_features(tcp_server PRIVATE cxx_std_20)
target_compile_options(tcp_server PRIVATE -Wall -Wextra -Werror)