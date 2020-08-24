cmake_minimum_required(VERSION 3.13)
project(Probably_Monopoly)

set(CMAKE_CXX_STANDARD 17)

add_executable(Probably_Monopoly src/main.cpp
        src/util.h
        src/CircularList.cpp
        src/CircularList.h
        src/Dices.cpp
        src/Dices.h
        src/Player.cpp
        src/Player.h)