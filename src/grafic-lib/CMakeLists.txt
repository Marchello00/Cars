cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)

set(GLEVEL_SOURCE_LIB ../grafic-lib-src/glevel.cpp)

add_library(glevel STATIC ${GLEVEL_SOURCE_LIB})

set(GRACER_SOURCE_LIB ../grafic-lib-src/gracer.cpp)

add_library(gracer STATIC ${GRACER_SOURCE_LIB})

set(GCOMMON_SOURCE_LIB ../grafic-lib-src/gcommon.cpp)

add_library(gcommon STATIC ${GCOMMON_SOURCE_LIB})

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(gracer ${SFML_LIBRARIES})
    target_link_libraries(glevel ${SFML_LIBRARIES})
    target_link_libraries(gcommon ${SFML_LIBRARIES})
endif ()