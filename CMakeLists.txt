cmake_minimum_required(VERSION 3.9)
project(my_cpp_plan)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")


set(TRAFFIC_SIMULATION_DIR ${PROJECT_SOURCE_DIR}/traffic_simulation/src/include/)
include_directories(${TRAFFIC_SIMULATION_DIR})

add_subdirectory(traffic_simulation)
add_subdirectory(test)


enable_testing()