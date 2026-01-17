cmake_minimum_required(VERSION 3.20)
project(ToDoList)

set(CMAKE_CXX_STANDARD 11)

add_executable(ToDoList
        main.cpp
        Date.cpp
        Date.h
        Activity.cpp
        Activity.h
        ToDoList.h
        ToDoList.cpp
        )
add_executable(TestDate
        TestDate.cpp
        Date.cpp
        Date.h
)
add_executable(TestActivity
        TestActivity.cpp
        Activity.cpp
        Activity.h
        Date.cpp
        Date.h
)
add_executable(TestToDoList
        TestToDoList.cpp
        Activity.cpp
        Activity.h
        Date.cpp
        Date.h
        ToDoList.cpp
        ToDoList.h
)







