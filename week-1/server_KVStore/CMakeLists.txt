cmake_minimum_required(VERSION 3.22.1)

project(server LANGUAGES CXX)


add_executable(server src/main.cpp)

target_compile_features(server  PRIVATE cxx_std_20)
target_compile_options(server PRIVATE -Wall -Wextra -Werror -g3)