# Configuration

cmake_minimum_required(VERSION 3.8.2)

project(mygui-sfml LANGUAGES CXX VERSION 1.0)

set(CMAKE_BUILD_TYPE Release)

# SFML

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4 REQUIRED graphics window system)

# MyGUI

add_library(mygui-engine SHARED IMPORTED)
set_target_properties(mygui-engine PROPERTIES
    IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ext/lib/libMyGUIEngine.so")
set_target_properties(mygui-engine PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ext/include/MYGUI")

add_library(mygui-opengl3 STATIC IMPORTED)
set_target_properties(mygui-opengl3 PROPERTIES
    IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ext/lib/libMyGUI.OpenGL3Platform.a")
set_target_properties(mygui-opengl3 PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ext/include/MYGUI")

# mygui-sfml

add_library(mygui-sfml
    src/Event.cpp
    src/SFMLImageLoader.cpp)
target_include_directories(mygui-sfml PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/ext/include/MYGUI>
    $<BUILD_INTERFACE:${SFML_INCLUDE_DIR}>
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