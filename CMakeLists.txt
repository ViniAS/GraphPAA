cmake_minimum_required(VERSION 3.26)
project(GraphPAA)

set(CMAKE_CXX_STANDARD 17)

add_executable(GraphPAA main.cpp
        graphs.cpp
        graphs.h)
