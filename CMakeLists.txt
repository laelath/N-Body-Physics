cmake_minimum_required(VERSION 3.4)
project(NBodyPhysics)

add_subdirectory(libraries/glfw-3.1.2)
add_subdirectory(libraries/gl3w-master)
include_directories(libraries/glfw-3.1.2/include libraries/gl3w-master/include)

# set(SOURCE_FILES src/*.c)
file(GLOB SOURCE_FILES src/*.c)
add_executable(NBodyPhysics ${SOURCE_FILES})

target_link_libraries(NBodyPhysics glfw ${GLFW_LIBRARIES})
target_link_libraries(NBodyPhysics gl3w)
