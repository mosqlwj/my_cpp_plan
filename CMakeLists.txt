cmake_minimum_required(VERSION 3.9)
project(my_cpp_plan)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_executable(out concurrent/lesson_one/variadic_templates_and_member_functions/quiz.cpp)

# link pthread
find_package(Threads)
target_link_libraries (out ${CMAKE_THREAD_LIBS_INIT})
