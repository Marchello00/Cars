cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)

set(BASE_SOURCE_LIB ../lib-src/base.cpp)

add_library(base STATIC ${BASE_SOURCE_LIB})

set(CARS_SOURCE_LIB ../lib-src/cars.cpp)

add_library(cars STATIC ${CARS_SOURCE_LIB})

set(PARTS_SOURCE_LIB ../lib-src/parts.cpp)

add_library(parts STATIC ${PARTS_SOURCE_LIB})

set(CONTAINER_SOURCE_LIB ../lib-src/container.cpp)

add_library(container STATIC ${CONTAINER_SOURCE_LIB})

set(BONUS_SOURCE_LIB ../lib-src/bonus.cpp)

add_library(bonus STATIC ${BONUS_SOURCE_LIB})

set(GROUND_SOURCE_LIB ../lib-src/ground.cpp)

add_library(ground STATIC ${GROUND_SOURCE_LIB})