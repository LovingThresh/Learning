cmake_minimum_required(VERSION 3.27)
project(Learning_boost)

set(CMAKE_CXX_STANDARD 20)

#set(Boost_ROOT "D:/C++/boost_1_83_0")
#set(BOOST_INCLUDEDIR "D:/C++/boost_1_83_0/boost")
#set(BOOST_LIBRARYDIR "D:/C++/boost_1_83_0/stage/lib")
#
#set(Boost_LIB_PREFIX "lib")
#set(Boost_COMPILER "-clang17")
#set(Boost_ARCHITECTURE "-x64")
#
set(Boost_USE_STATIC_LIBS ON)
set(BOOST_COMPONENTS date_time chrono filesystem iostreams regex system thread json)
find_package(Boost 1.83.0 REQUIRED COMPONENTS ${BOOST_COMPONENTS})
add_executable(Learning_boost Learning_boost.cpp)

#target_link_libraries(Learning_boost PRIVATE Boost::boost Boost::json Boost::filesystem Boost::system Boost::date_time Boost::chrono Boost::iostreams Boost::regex Boost::thread)
target_link_libraries(Learning_boost PRIVATE Boost::boost Boost::json)
#target_link_libraries(Learning_boost PRIVATE Boost::boost Boost::json ${Boost_FILESYSTEM_LIBRARIES} ${Boost_SYSTEM_LIBRARIES} ${Boost_JSON_LIBRARIES} ${Boost_LIBRARIES} ${Boost_INCLUDE_DIRS} )
#target_link_libraries(Learning_boost PRIVATE Boost::system Boost::filesystem Boost::json)
#target_include_directories(Learning_boost PRIVATE ${Boost_INCLUDE_DIRS})
#target_link_libraries(Learning_boost PRIVATE ${Boost_LIBRARIES})
#target_link_librar/ies(Learning_boost PRIVATE ${Boost_FILESYSTEM_LIBRARIES})
#include_directories("C:/Program Files/vcpkg/installed/x64-mingw-dynamic/include")
#link_directories("C:/Program Files/vcpkg/installed/x64-mingw-dynamic/lib")
#link_libraries("libboost_json")
#TARGET_LINK_LIBRARIES(Learning_boost ${Boost_LIBRARIES})