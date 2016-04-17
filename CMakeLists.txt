cmake_minimum_required(VERSION 3.3)
project(HMM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp creature.h undead.h vampire.h skeleton_archer.h archer.h map.h player.h id.h the_game.h Tent_ambulance.h doctor.h warrior.h monk.h elf.h)
add_executable(HMM ${SOURCE_FILES})