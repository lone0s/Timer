cmake_minimum_required(VERSION 3.23)
project(Chrono)

set(CMAKE_CXX_STANDARD 11)

include_directories(../Logger)

add_executable(Chrono main.cpp Chrono.cpp Chrono.h ../Logger/Logger.h ../Logger/Logger.cpp)
