cmake_minimum_required(VERSION 3.26)
project(GraphPAA)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
add_executable(GraphPAA main.cpp
        graphs.cpp
        graphs.h)
target_link_libraries(GraphPAA gtest gtest_main)