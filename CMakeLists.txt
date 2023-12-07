cmake_minimum_required(VERSION 3.26)
project(Learning)

set(CMAKE_CXX_STANDARD 17)

include_directories("D:/C++/Eigen")
#include_directories("D:/C++/boost_1_83_0/boost-windows-x86_64-gcc/include/boost-1_83")
#set(Boost_DEBUG ON)
#set(Boost_ROOT "D:/C++/boost_1_83_0")
#set(BOOST_INCLUDEDIR "D:/C++/boost_1_83_0/boost")
set(Boost_INCLUDE_DIR "D:/C++/boost_1_83_0")
set(ENV{BOOST_INCLUDEDIR} "D:/C++/boost_1_83_0/boost")
set(ENV{BOOST_LIBRARYDIR} "D:/C++/boost_1_83_0/stage/lib")

#set(Boost_LIBRARYDIR "D:/C++/boost_1_83_0/stage/lib")
set(Boost_LIB_PREFIX "lib")
set(Boost_ARCHITECTURE "-x64")

#find_package(Boost 1.83 REQUIRED)
find_package(Boost 1.83 REQUIRED COMPONENTS filesystem json)
if(Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIRS})
endif()
# set(Boost_INCLUDE_DIR D:/C++/boost_1_83_0/boost-windows-x86_64-gcc/include/boost-1_83)
# set(Boost_LIBRARY_DIR D:/C++/boost_1_83_0/stage/lib)
#set(Boost_USE_STATIC_LIBS ON)
#set(Boost_ARCHITECTURE "-x64")

#include_directories(Boost_INCLUDE_DIR)

#find_package(Boost 1.83.0 COMPONENTS log thread system regex REQUIRED)
#include_directories("D:/C++/boost_1_83_0")
#link_directories("D:/C++/boost_1_83_0/boost-windows-x86_64-gcc/lib")


add_subdirectory(Chapter3)
add_subdirectory(Chapter4)
add_subdirectory(Chapter-boost)
add_executable(Learning Chapter2/Exercise_2_5.cpp
        main.cpp
        Chapter1/Exercise_1.cpp
        Chapter2/Exercise_2.cpp
        Chapter2/Exercise_2_2.cpp
        )

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
if(Boost_FOUND)
        target_link_libraries(Learning_boost ${Boost_LIBRARIES})
endif()