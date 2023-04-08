cmake_minimum_required(VERSION 3.16)

project(testing)


# Define MY_SOURCES to be a list of all the source files for my game 
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")


add_executable(${PROJECT_NAME})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

include(../Resources.cmake)

target_compile_definitions(${PROJECT_NAME} PUBLIC LLGE_TESTS_FOLDER_PATH="${CMAKE_SOURCE_DIR}/testsFolder/")


target_sources(${PROJECT_NAME} PRIVATE ${MY_SOURCES})


if(MSVC) # If using the VS compiler...

	target_compile_definitions(${PROJECT_NAME} PUBLIC _CRT_SECURE_NO_WARNINGS)
	#set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
	set_property(TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDebug<$<CONFIG:Debug>:Debug>") #making sure again that we don't use the dynamic runtime
	set_property(TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
endif()

if(WIN32)
	target_compile_definitions(${PROJECT_NAME} PUBLIC _WIN32) 
  
endif()

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")



target_link_libraries(${PROJECT_NAME} PRIVATE glm glfw 
	glad stb_image stb_truetype raudio imgui moduleExample fileManipulation core window logging stringManipulation)