cmake_minimum_required(VERSION 3.9)
project(Cars)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)

include_directories(.)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)

