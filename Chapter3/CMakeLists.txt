cmake_minimum_required(VERSION 3.26)

project(LearningChapter3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Learning_Chapter3 main.cpp
        Chapter3_1.cpp
        Chapter3.h
)
add_executable(Exercise_3_2 Chapter_3.cpp)
add_executable(Learning_Iterator iterator.cpp)