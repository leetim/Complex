cmake_minimum_required(VERSION 3.0)


project(test1)
#set( CMAKE_CXX_FLAGS "-O0 -Wall -pedantic -ansi -std=c++11" )
add_definitions(-Wall -ansi -pthread)
set(CMAKE_EXE_LINKER_FLAGS "-pthread -std=c++11")
include_directories(../include)
include_directories(./include)

#add_library(gtest.a STATIC IMPORTED)
#add_library(gtest.a STATIC IMPORTED)

add_library(gtest STATIC IMPORTED)
set_property(TARGET gtest PROPERTY IMPORTED_LOCATION ../gtestLib/libgtest.a)
add_library(gtest_main STATIC IMPORTED)
set_property(TARGET gtest_main PROPERTY IMPORTED_LOCATION ../gtestLib/libgtest_main.a)
add_library(gmock STATIC IMPORTED)
set_property(TARGET gmock PROPERTY IMPORTED_LOCATION ../gtestLib/libgmock.a)
add_library(gmock_main STATIC IMPORTED)
set_property(TARGET gmock_main PROPERTY IMPORTED_LOCATION ../gtestLib/libgmock_main.a)
add_library(complex1 STATIC IMPORTED)
set_property(TARGET complex1 PROPERTY IMPORTED_LOCATION ../../lib/libcomplex.a)

#link_directories(./gtestLib)
add_executable(myTest ./test.cpp)
target_link_libraries(myTest gtest gtest_main gmock gmock_main)
target_link_libraries(myTest complex1)
