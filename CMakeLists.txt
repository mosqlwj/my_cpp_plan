cmake_minimum_required(VERSION 3.0)
project(my_leetcode_plan)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_executable(out  greedy/435_eraseOverlapIntervals.cpp greedy/452_findMinArrowShots.cpp)