cmake_minimum_required(VERSION 3.15)

project(IMAGE_PROCESSING_CPP)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenCV package
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(IMAGE_PROCESSING_CPP source/main.cpp source/image.cpp source/functions.cpp)

# Link OpenCV libraries to your target
target_link_libraries(IMAGE_PROCESSING_CPP ${OpenCV_LIBS})
