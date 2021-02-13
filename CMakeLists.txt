cmake_minimum_required(VERSION 3.10)

project(Kk_algorithms)

add_executable(${PROJECT_NAME} main.cpp )

add_subdirectory(kk_algorithms)

target_include_directories(${PROJECT_NAME} PRIVATE kk_algorithms/include)
target_link_directories(${PROJECT_NAME} PRIVATE kk_algorithms)

target_link_libraries(${PROJECT_NAME} kkdivideandconquer kkalgorithms)
