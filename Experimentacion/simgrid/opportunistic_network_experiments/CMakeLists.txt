cmake_minimum_required(VERSION 2.8.8)

project(SimGridTemplateProject) # TODO: give a real name to your project here

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(SimGrid 3.22 REQUIRED) # This template requires SimGrid v3.22

include_directories(${SimGrid_INCLUDE_DIR})

foreach (experiment ping-pong master-workers first_network one_disconnection_network)
  add_executable       (${experiment} EXCLUDE_FROM_ALL ${experiment}/${experiment}.cpp)	
  target_link_libraries(${experiment} simgrid)
  set_target_properties(${experiment} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${experiment})
  
endforeach()