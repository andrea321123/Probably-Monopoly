cmake_minimum_required(VERSION 3.13)
project(Probably_Monopoly)

set(CMAKE_CXX_STANDARD 17)

add_executable(Probably_Monopoly src/main.cpp
        src/CircularList.cpp
        src/CircularList.h
        )