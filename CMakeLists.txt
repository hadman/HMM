cmake_minimum_required(VERSION 3.3)
project(HMM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp creature.h undead.h vampire.h)
add_executable(HMM ${SOURCE_FILES})