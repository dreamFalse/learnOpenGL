cmake_minimum_required(VERSION 3.14) 
project(load_model) 

find_package(glfw3 REQUIRED) 
find_package(assimp REQUIRED) 

file(GLOB SOURCE_FILES ${CMAKE_SOURCE_DIR}/thirdparty/src/glad.c main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/thirdparty/include ${CMAKE_SOURCE_DIR}/utils) 

add_executable(${PROJECT_NAME} ${SOURCE_FILES}) 

target_link_libraries(${PROJECT_NAME} glfw dl assimp) 