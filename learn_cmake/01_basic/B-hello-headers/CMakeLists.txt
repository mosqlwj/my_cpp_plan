# 指定最小 CMake 版本要求
cmake_minimum_required(VERSION 3.9)
# 设置项目名称
project(B-hello-headers)
message(STATUS "Cur src dir" ${CMAKE_CURRENT_SOURCE_DIR})
#set(SOURCES
#        src/Hello.cpp
#        src/main.cpp
#        )

# GLOB指令和上面set指令的作用相同，但更加方便
file(GLOB SOURCES "src/*.cpp")
add_executable(hello_headers ${SOURCES})

# 用于帮助.cpp文件找到.h文件，没有该指令，则无法识别头文件路径
# CMAKE_CURRENT_SOURCE_DIR表示当前Cmakelist.txt所在路径
target_include_directories(hello_headers PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)