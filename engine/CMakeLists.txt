cmake_minimum_required(VERSION 3.19.4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER "g++")
set(MODULE_NAME engine_lib)
set(SDL2_DIR D:/Projects/Libaries/SDL2-2.0.14/x86_64-w64-mingw32/lib/cmake/SDL2)

# Find and Include SDL2 Libaries
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_library(${MODULE_NAME} STATIC
    colliders/hexagonalCollider.cpp
    objects/gameObject.cpp
    math/geometryHelpers.cpp
)
target_include_directories (${MODULE_NAME} PUBLIC headers)
