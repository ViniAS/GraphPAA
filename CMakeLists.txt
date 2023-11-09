cmake_minimum_required(VERSION 3.11)
project(GraphPAA)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
add_executable(GraphPAA main.cpp
        Graphs/Graph.cpp
        Graphs/Graph.h
        Graphs/GraphMatrix.cpp
        Graphs/GraphMatrix.h
        Graphs/GraphList.cpp
        Graphs/GraphList.h
        Graphs/GraphListWeighted.cpp
        Graphs/GraphListWeighted.h
)
target_link_libraries(GraphPAA gtest gtest_main)