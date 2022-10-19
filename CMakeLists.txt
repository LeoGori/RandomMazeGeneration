cmake_minimum_required(VERSION 3.9)
project(RandomMazeGeneration)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_NAME RandomMazeGeneration)

FILE(GLOB MySources "*.h" "*.cpp")
add_executable(${EXECUTABLE_NAME} ${MySources})

set(SFML_INCLUDE_DIR "SFML-2.5.0/include")
set(SFML_LIBRARY_DIR "SFML-2.5.0/lib")
set(SFML_DIR "SFML-2.5.0/lib/cmake/SFML")

####### GUI ##########
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
    target_link_libraries(${EXECUTABLE_NAME} sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
endif()

########GOOGLE TEST###########
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../include)
#add_subdirectory(test)
#add_library(core ${SOURCE_FILE})
#target_link_libraries(Project core)
