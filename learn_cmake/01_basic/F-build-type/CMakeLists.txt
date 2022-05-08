# 指定最小 CMake 版本要求
cmake_minimum_required(VERSION 3.9)
# 设置项目名称
project(F-build-type)
message(STATUS "Cur src dir" ${CMAKE_CURRENT_SOURCE_DIR})

# Set a default build type if none was specified
#if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
#    message("Setting build type to 'RelWithDebInfo' as none was specified.")
#    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
#    # Set the possible values of build type for cmake-gui
#    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
#            "MinSizeRel" "RelWithDebInfo")
#endif()
set(CMAKE_BUILD_TYPE Release CACHE STRING "set build type to debug")
# Add an executable
add_executable(F-build-type main.cpp)