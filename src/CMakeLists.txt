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

set(GRAPHICAL_LIBS gracer ggame glevel gwindow genums gcommand)

target_link_libraries(Cars ${GRAPHICAL_LIBS})
target_link_libraries(Cars tinyxml2)
target_link_libraries(Cars tiledmap)

if (NOT CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)

    set(data_SHADOW maps images)

    foreach(item IN LISTS data_SHADOW)
        message(STATUS ${item})
        add_custom_command(
                TARGET Cars
                POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/${item}" "${CMAKE_CURRENT_BINARY_DIR}/${item}"
                COMMENT "Copying ${item}"
        )
    endforeach()
endif()

set(CMAKE_INSTALL_PREFIX ../bin)

install(TARGETS Cars DESTINATION ${CMAKE_INSTALL_PREFIX}/dbg CONFIGURATIONS Debug)
install(DIRECTORY ../maps DESTINATION ${CMAKE_INSTALL_PREFIX}/dbg CONFIGURATIONS Debug)
install(DIRECTORY ../images DESTINATION ${CMAKE_INSTALL_PREFIX}/dbg CONFIGURATIONS Debug)

install(TARGETS Cars DESTINATION ${CMAKE_INSTALL_PREFIX} CONFIGURATIONS Release)
install(DIRECTORY ../maps DESTINATION ${CMAKE_INSTALL_PREFIX} CONFIGURATIONS Release)
install(DIRECTORY ../images DESTINATION ${CMAKE_INSTALL_PREFIX} CONFIGURATIONS Release)