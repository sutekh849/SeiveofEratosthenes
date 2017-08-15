cmake_minimum_required (VERSION 3.0)
project (seive)
set (SEIVE_VERSION_MAJOR 3)
set (SEIVE_VERSION_MINOR 0)
SET(CMAKE_CXX_FLAGS "-std=c++0x -O3 -msse3 -march=native")
include_directories("${PROJECT_BINARY_DIR}")
#find_package(Boost 1.53)
#if(Boost_FOUND)
#	include_directories(${Boost_INCLUDE_DIRS})
add_executable(seive main.cpp)
target_link_libraries (seive ${EXTRA_LIBS})
#endif()


