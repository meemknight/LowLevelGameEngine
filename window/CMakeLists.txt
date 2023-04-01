cmake_minimum_required(VERSION 3.16)

project(window)
include(../ModuleCommon.cmake)
target_link_libraries(${PROJECT_NAME} PUBLIC glm glfw glad) #optionally link with other modules or libraries

