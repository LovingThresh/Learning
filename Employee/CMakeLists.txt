cmake_minimum_required(VERSION 3.27)
project(Learning_Employee)

set(CMAKE_CXX_STANDARD 20)

add_executable(Learning_Employee EmployeeTest.cpp
        Employee.cpp
        Employee.h
)
