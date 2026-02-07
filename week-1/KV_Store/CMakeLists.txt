cmake_minimum_required(VERSION 3.22.1)



project(Myproject LANGUAGES CXX)

add_executable(kvStore src/main.c src/kv_store.cpp)

target_compile_features(kvStore PRIVATE cxx_std_20)
target_compile_options(kvStore PRIVATE -Wall -Wextra -Werror)