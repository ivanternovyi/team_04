cmake_minimum_required(VERSION 3.6)
project(Manager)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Entity/Task.cpp Entity/Task.h DTO/Data.cpp DTO/Data.h BL/Menu.cpp)
add_executable(Manager ${SOURCE_FILES})