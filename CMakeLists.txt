cmake_minimum_required(VERSION 3.20)
project(ToDoList)

set(CMAKE_CXX_STANDARD 11)

add_executable(ToDoList main.cpp
        Date.cpp
        Date.h
        Activity.cpp
        Activity.h)
