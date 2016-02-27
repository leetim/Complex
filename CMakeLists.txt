cmake_minimum_required(VERSION 3.0)

project(complex)

include_directories(./include)

add_library(complex STATIC ./source/complex.cpp)