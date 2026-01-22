cmake_minimum_required(VERSION 3.14) 
project(window) 

# find_package(OpenGL REQUIRED) 
find_package(glfw3 REQUIRED)

file(GLOB SOURCE_FILES ${CMAKE_SOURCE_DIR}/thirdparty/src/glad.c main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/thirdparty/include ${CMAKE_SOURCE_DIR}/shader)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} glfw dl) 

