cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)

add_library(tiledmap STATIC level.cpp)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    link_libraries(tiledmap ${SFML_LIBRARIES})
endif ()