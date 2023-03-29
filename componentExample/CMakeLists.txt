cmake_minimum_required(VERSION 3.16)

project(componentExample)



# Define MY_SOURCES to be a list of all the source files for my game 
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")


add_library(componentExample)
target_sources(componentExample PRIVATE "${MY_SOURCES}")
target_include_directories(componentExample PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(componentExample PUBLIC core) #link with other components or libraries
