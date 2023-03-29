cmake_minimum_required(VERSION 3.16)

project(core)



# Define MY_SOURCES to be a list of all the source files for my game 
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(core)
target_sources(core PRIVATE "${MY_SOURCES}")
target_include_directories(core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

