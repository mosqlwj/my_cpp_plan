cmake_minimum_required(VERSION 3.9)
project(my_cpp_plan)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(learn_cmake/hello_cmake)
add_subdirectory(leetcode/system_design)

