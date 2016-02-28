cmake_minimum_required(VERSION 3.0)

project(complex)
add_definitions(-Wall -ansi -pthread)
set(CMAKE_EXE_LINKER_FLAGS "-pthread -std=c++11")

include_directories(./include)

add_library(complex STATIC ./source/complex.cpp)