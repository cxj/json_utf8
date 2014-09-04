# Very basic CMake project for CLion users, or anyone who likes to use CMake.
cmake_minimum_required(VERSION 2.8.4)
project(json_utf8)

set(SOURCE_FILES JSON.cpp JSONValue.cpp demo/main.cpp demo/example.cpp demo/testcases.cpp)
add_executable(json_utf8 ${SOURCE_FILES})
