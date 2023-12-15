cmake_minimum_required(VERSION 3.27)
project(Learning)

set(CMAKE_CXX_STANDARD 20)

#include_directories("D:/C++/Eigen")
#set(Boost_DEBUG ON)
#set(Boost_ROOT "D:/C++/boost_1_83_0")
#set(BOOST_INCLUDEDIR "D:/C++/boost_1_83_0/boost")
#set(BOOST_LIBRARYDIR "D:/C++/boost_1_83_0/stage/lib")
#
#set(Boost_LIB_PREFIX "lib")
#set(Boost_COMPILER "-clang17")
#set(Boost_ARCHITECTURE "-x64")
find_package(Eigen3 REQUIRED)
find_package(CGAL CONFIG REQUIRED)
find_package(Boost 1.83.0 REQUIRED COMPONENTS system filesystem json)

add_subdirectory(String)
add_subdirectory(Chapter3)
add_subdirectory(Chapter4)
add_subdirectory(Employee)
add_subdirectory(OOP_Learning)
add_subdirectory(Chapter-boost)
add_executable(Learning main.cpp)
        # main.cpp
        # Chapter2/Exercise_2_5.cpp
#        Chapter1/Exercise_1.cpp
#        Chapter2/Exercise_2.cpp
#        Chapter2/Exercise_2_2.cpp
#        )

        # Timer/Timer_function.cpp
        # Chapter4/Stack.cpp
        # Chapter4/Stack.hpp
        # Chapter4/Queue.cpp
        # Chapter4/Queue.hpp
        # Chapter4/main.cpp)
#        Chapter2/Exercise_2_2.cpp
#        Chapter1/Exercise_1.cpp
#        Chapter1/Exercise_1.hpp
#        Chapter2/Exercise_2.hpp
#        Chapter2/Exercise_2.cpp
#        OOP_Learning/Stock.hpp
#        Chapter2/Exercise_2_2.cpp)
#if(Boost_FOUND)
#        target_link_libraries(Learning_boost ${Boost_LIBRARIES})
#endif()add_executable(Learning_UI Employee/main.cpp)
