cmake_minimum_required(VERSION 2.8)
project(filter-magic)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/src/include)
add_executable(filter-magic src/main.cpp src/filter.cpp src/log.cpp)
target_link_libraries(filter-magic ${OpenCV_LIBS})

