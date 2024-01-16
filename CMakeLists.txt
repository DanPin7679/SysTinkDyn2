cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

project(STDyn VERSION 1.0.0)

set(SOURCES
    src/stdyn/cmd/stdyn.cpp
    src/stdyn/schema/stdynschema.cpp
    src/stdyn/render/render.cpp 
    src/stdyn/render/screen.cpp
    src/stdyn/render/shapes.cpp
    src/stdyn/cgmath/vec.cpp
    src/ext/glad/src/glad.c
)
set(INCLUDE
    src/stdyn/schema
    src/stdyn/render
    src/stdyn/cgmath
    /Users/danypineault/Documents/glfw-3.3.9.bin.MACOS/include
    /Users/danypineault/Documents/Code/cpp/SysTinkDyn2/src/ext/glad/include/
)

add_executable(STDyn ${SOURCES})

target_include_directories(STDyn
    PRIVATE 
        /opt/homebrew/Cellar/boost/1.83.0/include
    PRIVATE
        /Users/danypineault/Desktop/SDL2.framework/Headers
    PRIVATE
        /Users/danypineault/Desktop/SDL2_image.framework/Versions/A/Headers
    PRIVATE 
        ${INCLUDE}
)

target_link_libraries(STDyn 
    PRIVATE
        /Users/danypineault/Documents/glfw-3.3.9.bin.MACOS/lib-arm64/libglfw.3.dylib
    PRIVATE 
    /Users/danypineault/Desktop/SDL2.framework/SDL2
    /Users/danypineault/Desktop/SDL2_image.framework/SDL2_image
)



