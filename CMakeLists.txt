# Configuration

cmake_minimum_required(VERSION 3.8.2)

project(mygui-sfml LANGUAGES CXX VERSION 1.0)

set(CMAKE_BUILD_TYPE Release)

# SFML

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules" ${CMAKE_MODULE_PATH})

set(SFML_DIR "" CACHE PATH "")
option(SFML_STATIC "" OFF)
if(SFML_STATIC)
    set(SFML_STATIC_LIBRARIES TRUE)
endif()
find_package(SFML 2.4 REQUIRED graphics window system)

# MyGUI

set(MYGUI_INCLUDE_DIR "" CACHE PATH "")
set(MYGUI_ENGINE_LIBRARY "" CACHE FILEPATH "")
set(MYGUI_OPENGL3_LIBRARY "" CACHE FILEPATH "")
option(MYGUI_STATIC "" OFF)
option(MYGUI_OPENGL3_STATIC "" OFF)

if(MYGUI_STATIC)
    add_library(mygui-engine STATIC IMPORTED)
else()
    add_library(mygui-engine SHARED IMPORTED)
endif()
set_target_properties(mygui-engine PROPERTIES
    IMPORTED_LOCATION "${MYGUI_ENGINE_LIBRARY}")
set_target_properties(mygui-engine PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${MYGUI_INCLUDE_DIR}")

if(MYGUI_OPENGL3_STATIC)
    add_library(mygui-opengl3 STATIC IMPORTED)
else()
    add_library(mygui-opengl3 SHARED IMPORTED)
endif()
set_target_properties(mygui-opengl3 PROPERTIES
    IMPORTED_LOCATION "${MYGUI_OPENGL3_LIBRARY}")
set_target_properties(mygui-opengl3 PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${MYGUI_INCLUDE_DIR}")

# mygui-sfml

add_library(mygui-sfml
    src/Event.cpp
    src/SFMLImageLoader.cpp)
target_link_libraries(mygui-sfml PUBLIC
    sfml-graphics
    mygui-engine
    mygui-opengl3)
target_include_directories(mygui-sfml PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

# Examples

option (BUILD_EXAMPLES "Build the examples." ON)
if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Install

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_BINARY_DIR}/mygui-sfmlConfigVersion.cmake
    VERSION
    COMPATIBILITY AnyNewerVersion)
configure_package_config_file(
    ${CMAKE_SOURCE_DIR}/cmake/mygui-sfmlConfig.cmake.in
    ${CMAKE_BINARY_DIR}/mygui-sfmlConfig.cmake
    INSTALL_DESTINATION lib/cmake/mygui-sfml)

install(TARGETS mygui-sfml EXPORT mygui-sfmlTargets
    INCLUDES DESTINATION include
    ARCHIVE DESTINATION lib)
install(EXPORT mygui-sfmlTargets
    FILE mygui-sfmlTargets.cmake
    DESTINATION lib/cmake/mygui-sfml)
install(FILES
    ${CMAKE_BINARY_DIR}/mygui-sfmlConfigVersion.cmake
    ${CMAKE_BINARY_DIR}/mygui-sfmlConfig.cmake
    DESTINATION lib/cmake/mygui-sfml)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include)