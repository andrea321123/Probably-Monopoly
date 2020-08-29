cmake_minimum_required(VERSION 3.13)
project(Probably_Monopoly)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(Probably_Monopoly src/main.cpp
        src/util.h
        src/CircularList.cpp
        src/CircularList.h
        src/Dices.cpp
        src/Dices.h
        src/Player.cpp
        src/Player.h
        src/Board.cpp
        src/Board.h
        src/SimulationResult.h
        src/cards.h
        src/squareToName.h src/squareToName.cpp)