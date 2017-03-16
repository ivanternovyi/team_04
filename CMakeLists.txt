cmake_minimum_required(VERSION 3.6)
project(manager_tasks)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Entity/Task.cpp Entity/Task.h BL/Menu.cpp DTO/DTOTask.cpp DTO/DTOTask.h)
add_executable(manager_tasks ${SOURCE_FILES})