cmake_minimum_required(VERSION 3.19.4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER "g++")
set(PROJECT game)
set(ENGINE_LIB engine_lib)

# Find and Include SDL2 Libaries
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add the executable
add_executable(${PROJECT} main.cpp game.cpp)
target_link_libraries(${PROJECT} PUBLIC ${ENGINE_LIB} ${SDL2_LIBRARIES})


