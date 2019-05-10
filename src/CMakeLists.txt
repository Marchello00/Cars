cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)

include_directories(lib)
include_directories(grafic-lib)
include_directories(tinyxml2)
include_directories(helpers-lib)

add_subdirectory(lib)
add_subdirectory(grafic-lib)
add_subdirectory(tinyxml2)
add_subdirectory(helpers-lib)

add_executable(Cars main.cpp)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Cars ${SFML_LIBRARIES})
endif ()

set(GRAPHICAL_LIBS gracer)

target_link_libraries(Cars ${GRAPHICAL_LIBS})
target_link_libraries(Cars tinyxml2)
target_link_libraries(Cars tiledmap)
