cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)

set(GLEVEL_SOURCE_LIB ../grafic-lib-src/glevel.cpp)

add_library(glevel STATIC ${GLEVEL_SOURCE_LIB})

set(GRACER_SOURCE_LIB ../grafic-lib-src/gracer.cpp)

add_library(gracer STATIC ${GRACER_SOURCE_LIB})

set(GWINDOW_SOURCE_LIB ../grafic-lib-src/gwindow.cpp)

add_library(gwindow STATIC ${GWINDOW_SOURCE_LIB})

set(GGAME_SOURCE_LIB ../grafic-lib-src/ggame.cpp)

add_library(ggame STATIC ${GGAME_SOURCE_LIB})

set(GENUMS_SOURCE_LIB ../grafic-lib-src/genums.cpp)

add_library(genums STATIC ${GENUMS_SOURCE_LIB})

set(GCOMMAND_SOURCE_LIB ../grafic-lib-src/gcommand.cpp)

add_library(gcommand STATIC ${GCOMMAND_SOURCE_LIB})

set(GBONUS_SOURCE_LIB ../grafic-lib-src/gbonus.cpp)

add_library(gbonus STATIC ${GBONUS_SOURCE_LIB})

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(gracer ${SFML_LIBRARIES})
    target_link_libraries(glevel ${SFML_LIBRARIES})
    target_link_libraries(gwindow ${SFML_LIBRARIES})
    target_link_libraries(ggame ${SFML_LIBRARIES})
    target_link_libraries(gcommand ${SFML_LIBRARIES})
    target_link_libraries(gbonus ${SFML_LIBRARIES})
endif ()

include_directories(../lib)
set(LIBS cars parts base ground bonus)
target_link_libraries(gracer ${LIBS})
target_link_libraries(ggame ${LIBS})
target_link_libraries(gcommand ${LIBS})
target_link_libraries(gracer gbonus)
