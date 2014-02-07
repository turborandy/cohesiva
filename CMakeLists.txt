cmake_minimum_required (VERSION 2.6)
project (Cohesiva)
add_executable(Cohesiva main.cpp)

add_subdirectory(glfw-3.0.4)
include_directories(glfw-3.0.4/include)
target_link_libraries(Cohesiva glfw ${GLFW_LIBRARIES})

