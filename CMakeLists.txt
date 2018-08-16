cmake_minimum_required(VERSION 2.8)
project(FilterMagic)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(FilterMagic src/main.cpp)
target_link_libraries(FilterMagic ${OpenCV_LIBS})

