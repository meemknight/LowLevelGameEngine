cmake_minimum_required(VERSION 3.16)

project(moduleExample)



# Define MY_SOURCES to be a list of all the source files for my game 
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")


add_library(moduleExample)
target_sources(moduleExample PRIVATE "${MY_SOURCES}")
target_include_directories(moduleExample PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(moduleExample PUBLIC core) #link with other modules or libraries
