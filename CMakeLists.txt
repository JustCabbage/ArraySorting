cmake_minimum_required(VERSION 3.0.0)
project(ArraySorting VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Dependencies/SFML)
add_executable(ArraySorting main.cpp Core/Visualizer.cpp)
target_link_libraries(ArraySorting PRIVATE sfml-window sfml-graphics)