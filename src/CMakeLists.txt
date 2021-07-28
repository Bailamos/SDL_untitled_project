cmake_minimum_required(VERSION 3.19.4)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT game)
set(ENGINE_LIB engine_lib)

# Find and Include SDL2 Libaries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(${PROJECT} SDL2::Main)
target_link_libraries(${PROJECT} SDL2::Image)

# Add the executable
add_executable(${PROJECT} main.cpp game.cpp entities/treeMapTile.cpp entities/map.cpp)
target_link_libraries(${PROJECT} PUBLIC ${ENGINE_LIB} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
# target_include_directories(${PROJECT} PUBLIC consants.hpp)
set_target_properties(${PROJECT} PROPERTIES WIN32_EXECUTABLE FALSE)