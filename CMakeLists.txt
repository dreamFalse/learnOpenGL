cmake_minimum_required(VERSION 3.14) 
project(learnOpenGL) 

# find_package(OpenGL REQUIRED) 
find_package(glfw3 REQUIRED)

add_subdirectory(demo_window)
add_subdirectory(demo_lighting)
add_subdirectory(demo_loadmodel)
