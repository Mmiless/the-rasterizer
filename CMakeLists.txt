cmake_minimum_required(VERSION 3.15)
project(Rasterizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(rasterizer src/main.cpp)

target_link_libraries(rasterizer ${SDL2_LIBRARIES})