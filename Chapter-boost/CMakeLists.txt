cmake_minimum_required(VERSION 3.27)
project(Learning_boost)

set(CMAKE_CXX_STANDARD 20)


add_executable(Learning_boost Learning_boost.cpp
)
target_include_directories(Learning_boost PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(Learning_boost PRIVATE ${Boost_LIBRARIES})