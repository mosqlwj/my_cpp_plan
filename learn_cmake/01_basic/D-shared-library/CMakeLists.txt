# 指定最小 CMake 版本要求
cmake_minimum_required(VERSION 3.9)
# 设置项目名称
project(D-shared-library)
message(STATUS "Cur src dir" ${CMAKE_CURRENT_SOURCE_DIR})

add_library(hello_library SHARED src/Hello.cpp)
# 取别名
add_library(hello::library ALIAS hello_library)

target_include_directories(hello_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


add_executable(D-shared-library src/main.cpp)
target_link_libraries(D-shared-library PRIVATE hello::library)
