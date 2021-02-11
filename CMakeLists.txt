cmake_minimum_required(VERSION 3.10)

project(Kk_algorithms)

add_executable(${PROJECT_NAME} main.cpp )

add_subdirectory(src)
include_directories(${CMAKE_SOURCE_DIR}/src/include)
