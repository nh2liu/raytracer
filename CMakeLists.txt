cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(raytracer)
include_directories(include)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cc")
 
add_executable(raytracer ${SOURCES})