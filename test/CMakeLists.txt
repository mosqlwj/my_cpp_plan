
#add_executable(traffic_simulation_test ./TrafficSimulation_Test.cpp)
#
#target_link_libraries(traffic_simulation_test traffic_simulation_lib)
#
#add_test(NAME traffic_simulation_test COMMAND traffic_simulation_test)

function(cpp_test test_file link_file)
    # get file name
    get_filename_component(test_target_name ${test_file} NAME_WE)
    add_executable(${test_target_name} ${test_file})
    target_link_libraries(${test_target_name} ${link_file})
    add_test(NAME ${test_target_name} COMMAND ${test_target_name})
endfunction(cpp_test)

cpp_test(TrafficSimulation_Test.cpp traffic_simulation_lib)