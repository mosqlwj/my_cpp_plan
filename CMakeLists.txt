cmake_minimum_required(VERSION 3.0)
project(my_leetcode_plan)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# set(ICTEST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/src/include)
# include_directories(${ICTEST_INCLUDE_DIR})



# static link lib
# add_subdirectory(thirdparty)

aux_source_directory(cpp_primer/chap15 SRC)
add_executable(out ${SRC})

# target_link_libraries(ictest thirdparty)
