# 指定最小 CMake 版本要求
cmake_minimum_required(VERSION 3.9)
# 设置项目名称
project(split_library)

# 添加 libanswer 库目标，STATIC 指定为静态库
add_library(libanswer STATIC answer.cpp)

add_executable(split_library main.cpp)
# 为 split_library 可执行目标链接 libanswer
target_link_libraries(split_library libanswer)