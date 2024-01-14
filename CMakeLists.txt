cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

project(STDyn VERSION 1.0.0)

set(SOURCES
    src/stdyn/cmd/stdyn.cpp
    src/stdyn/schema/stdynschema.cpp 
    src/stdyn/render/renderglwf.cpp 
    src/ext/glad/src/glad.c
)
set(INCLUDE
    src/stdyn/schema
    src/stdyn/render
    /Users/danypineault/Documents/glfw-3.3.9.bin.MACOS/include
    /Users/danypineault/Documents/Code/cpp/SysTinkDyn2/src/ext/glad/include/
)
link_directories(/Users/danypineault/Documents/glfw-3.3.9.bin.MACOS/lib-arm64)
add_executable(STDyn ${SOURCES})

target_include_directories(STDyn
    PRIVATE 
        /opt/homebrew/Cellar/boost/1.83.0/include
    PRIVATE 
        ${INCLUDE}
)

target_link_libraries(STDyn libglfw.3.dylib)

