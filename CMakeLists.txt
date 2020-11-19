cmake_minimum_required(VERSION 3.13)
project(Ecemon)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Ecemon main.cpp, Creature.cpp Creature.h Attaque.cpp Attaque.h Carte.cpp Carte.h Energie.cpp Energie.h Speciale.h Speciale.cpp User.cpp User.h)


