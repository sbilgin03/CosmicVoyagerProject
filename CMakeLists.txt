cmake_minimum_required(VERSION 3.27)
project(CosmicVoyagerProject)

set(CMAKE_CXX_STANDARD 17)

include_directories(cmake-build-debug)

add_executable(CosmicVoyagerProject
        main.cpp
        cmake-build-debug/EventsAndFunctions.h
        cmake-build-debug/OtherFunctions.cpp
        cmake-build-debug/Events.cpp
)
