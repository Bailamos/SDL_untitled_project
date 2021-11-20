cmake_minimum_required(VERSION 3.19.4)

set(CMAKE_CXX_STANDARD 17)
set(MODULE_NAME engine_lib)

# Find and Include SDL2 Libaries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

add_library(${MODULE_NAME} STATIC
    colliders/hexagonalCollider.cpp
    objects/transform.cpp
    objects/camera.cpp
    objects/gameObject.cpp
    objects/textureLoader.cpp
    math/geometryHelpers.cpp
)
target_include_directories (${MODULE_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
