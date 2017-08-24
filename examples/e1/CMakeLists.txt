cmake_minimum_required(VERSION 2.8)

project(e1)

add_executable(e1 src/main.cpp)

target_link_libraries(e1 kdtree)
