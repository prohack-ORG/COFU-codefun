cmake_minimum_required (VERSION 3.8)

set (LOCAL_PATH call my-dir)

set (CMAKE_CXX_FLAGS "-DENABLE_DEBUG=0 -DENABLE_PROFILING=0" )

project (testGraph)

include_directories ($(LOCAL_PATH)/)

add_definitions(-std=c++11)

add_executable(testGraph Graph.cpp testGraph.cpp)