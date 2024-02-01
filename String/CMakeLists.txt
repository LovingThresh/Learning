cmake_minimum_required(VERSION 3.27)
project(Learning_String)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_TOOLCHAIN_FILE C:/Users/liuye/Desktop/vcpkg/scripts/buildsystems/vcpkg.cmake)
#find_package(CGAL CONFIG REQUIRED)
#find_package(Boost COMPONENTS filesystem system)

add_executable(Learning_String main.cpp
)
#target_link_libraries(Learning_String PRIVATE CGAL::CGAL ${Boost_FILESYSTEM_LIBRARIES} ${Boost_SYSTEM_LIBRARIES})
