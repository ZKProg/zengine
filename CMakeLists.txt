cmake_minimum_required(VERSION 3.1)
cmake_policy(SET CMP0048 NEW)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-w")

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

project(zengine VERSION 0.1)

include_directories(
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/configure
  )

configure_file(configure/conf.h.in configure/conf.h)

file(GLOB SOURCES "main.cpp" "./src/*.cpp" "./src/2D/*.cpp" "./src/3D/*.cpp")

add_executable(zengine ${SOURCES})

if (UNIX)

  target_link_libraries(
    zengine
    SDL2
    SDL2main
    SDL2_image
    SDL2_ttf
    SDL2_mixer
    GL
    GLEW
    pthread
    )
  
endif()
