cmake_minimum_required(VERSION 3.16)

project(logging)
include(../ModuleCommon.cmake)
target_link_libraries(${PROJECT_NAME} PRIVATE fileManipulation)
