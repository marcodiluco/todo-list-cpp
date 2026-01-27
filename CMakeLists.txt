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
        ToDoListTests.cpp
)


# GOOGLE TEST

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

#  ESEGUIBILE

add_executable(ToDoListTests
        ToDoListTests.cpp
        Activity.cpp
        Date.cpp
        ToDoList.cpp
)

target_link_libraries(ToDoListTests
        gtest
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(ToDoListTests)





