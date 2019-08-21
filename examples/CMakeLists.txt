# Executable

add_executable(example main.cpp)
target_compile_features(example PRIVATE cxx_std_17)
target_include_directories(mygui-sfml PUBLIC ${SFML_INCLUDE_DIR})
target_link_libraries(example PRIVATE
    ${SFML_LIBRARIES} ${SFML_DEPENDENCIES}
    mygui-sfml
    mygui-opengl3
    mygui-engine
    -lGL
    -lfreetype
    -ldl)