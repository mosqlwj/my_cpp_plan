find_package(OpenCV 4.1 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

file(GLOB TS_SRCS src/*.cpp)

add_library(traffic_simulation_lib ${TS_SRCS})
target_link_libraries(traffic_simulation_lib ${OpenCV_LIBRARIES})
#add_executable(traffic_simulation ${TS_SRCS})
#target_link_libraries(traffic_simulation ${OpenCV_LIBRARIES})