cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)

project(libs)

set(SOURCE_LIB base.cpp)

add_library(base STATIC ${SOURCE_LIB})