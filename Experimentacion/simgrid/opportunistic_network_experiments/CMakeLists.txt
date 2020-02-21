cmake_minimum_required(VERSION 2.8.8)

project(SimGridTemplateProject) # TODO: give a real name to your project here

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_RELEASE "-O0")

find_package(SimGrid 3.22 REQUIRED) # This template requires SimGrid v3.22

foreach (experiment ping-pong master-workers first_network no_disconnection_network one_disconnection_network big_network_no_disconnections big_network_disconnections)
	file(GLOB SOURCES utils/*.cpp)

	add_executable(${experiment} EXCLUDE_FROM_ALL ${experiment}/${experiment}.cpp ${SOURCES})
	target_link_libraries(${experiment} simgrid)
	set_target_properties(${experiment} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${experiment})
  
endforeach()
