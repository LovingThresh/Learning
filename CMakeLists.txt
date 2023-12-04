cmake_minimum_required(VERSION 3.26)
project(Learning)

set(CMAKE_CXX_STANDARD 17)

include_directories("D:/C++/Eigen")
include_directories("D:/C++/boost_1_83_0/boost-windows-x86_64-gcc/include/boost-1_83")
add_subdirectory(Chapter3)
add_subdirectory(Chapter4)
add_executable(Learning Chapter2/Exercise_2_5.cpp
        main.cpp
        Chapter1/Exercise_1.cpp
        Chapter2/Exercise_2.cpp
        Chapter2/Exercise_2_2.cpp)
        # Timer/Timer_function.cpp
        # Chapter4/Stack.cpp
        # Chapter4/Stack.h
        # Chapter4/Queue.cpp
        # Chapter4/Queue.h
        # Chapter4/main.cpp)
#        Chapter2/Exercise_2_2.cpp
#        Chapter1/Exercise_1.cpp
#        Chapter1/Exercise_1.h
#        Chapter2/Exercise_2.h
#        Chapter2/Exercise_2.cpp
#        OOP_Learning/Stock.h
#        Chapter2/Exercise_2_2.cpp)
