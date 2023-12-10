cmake_minimum_required(VERSION 3.27)
project(Learning_Employee)

set(CMAKE_CXX_STANDARD 20)

#if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#
#    add_compile_options(-fmodule-file=D:/development/CPP_Projects/Learning/precompiled_headers/iostream.pcm)
#
#endif()

add_executable(Learning_Employee EmployeeTest.cpp
        Employee.cpp
        Employee.hpp
)
add_executable(Learning_Database DatabaseTest.cpp
        Employee.cpp
        Employee.hpp
        Database.cpp
        Database.hpp
)
add_executable(Learning_UI main.cpp
        Employee.cpp
        Employee.hpp
        Database.cpp
        Database.hpp
)