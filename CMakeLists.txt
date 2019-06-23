cmake_minimum_required(VERSION 3.14)
project(Procedural_Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(Procedural_Project main.cpp)