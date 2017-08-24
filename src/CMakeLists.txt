cmake_minimum_required(VERSION 2.8)

add_library(kdtree
    kdtree.cpp
)

target_include_directories(kdtree PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
