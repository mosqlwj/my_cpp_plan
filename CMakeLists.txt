cmake_minimum_required(VERSION 3.0)
project(my_leetcode_plan)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_executable(out cpp_primer/chap12/test_str_blob.cpp cpp_primer/chap12/str_blob.cpp)