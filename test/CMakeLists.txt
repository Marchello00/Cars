cmake_minimum_required(VERSION 3.13)

project(Test)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# we use this to get code coverage
if (CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif ()


if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

if(MINGW)
    set(GTEST_DISABLE_PTHREADS ON)
endif()

if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
    set(WINDOWS_CMAKE_ARGS
            -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
            -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
            )
else(WIN32)
    set(WINDOWS_CMAKE_ARGS )
endif(WIN32)


include(cmake/googletest.cmake)
fetch_googletest(
        cmake
        ${PROJECT_BINARY_DIR}/googletest
)

enable_testing()

add_executable(TestBuilder builder_test.cpp)

target_link_libraries(TestBuilder gtest_main base)

#add_test(
#        NAME BuilderTest
#        COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/TestBuilder
#)
#
#add_test(
#        NAME BuilderTest2
#        COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/TestBuilder
#)

