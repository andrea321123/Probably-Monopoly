cmake_minimum_required(VERSION 3.13)
project(Probably_Monopoly_Test)

set(CMAKE_CXX_STANDARD 17)

add_executable(Probably_Monopoly_Test test.cpp
        ../src/CircularList.h
        ../src/CircularList.cpp
        ../src/Player.h
        ../src/Player.cpp
        PlayerTest.cpp
        CircularListTest.cpp)