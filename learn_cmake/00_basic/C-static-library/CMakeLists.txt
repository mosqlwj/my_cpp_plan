# 指定最小 CMake 版本要求
cmake_minimum_required(VERSION 3.9)
# 设置项目名称
project(C-static-library)
message(STATUS "Cur src dir" ${CMAKE_CURRENT_SOURCE_DIR})

add_library(hello_library STATIC src/Hello.cpp)

target_include_directories(hello_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


add_executable(C-static_library src/main.cpp)
target_link_libraries(C-static_library PRIVATE hello_library)
