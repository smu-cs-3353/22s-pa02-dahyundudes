cmake_minimum_required(VERSION 3.16)
project(22s_pa02)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE -O3)

#configure_file(input/shortTest.txt input/shortTest.txt COPYONLY)

add_executable(pa02 src/main.cpp src/Sort.h)
add_executable(pa02_test src/catch_setup.cpp src/test.cpp src/Sort.h)