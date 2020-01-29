#cmake for trees

cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
project (trees)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main main.cpp)

#add_library(trees trees.hpp)

#target_link_libraries(main trees)