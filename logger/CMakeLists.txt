cmake_minimum_required(VERSION 3.16)

project(logger)
include(../ModuleCommon.cmake)
target_link_libraries(${PROJECT_NAME} PRIVATE fileManipulation)