cmake_minimum_required(VERSION 2.8)
project(my-weberver)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_FLAGS "-std=c++14 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG  
    "-std=c++14 -O2 -fopenmp -pthread  -g -ggdb")


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)    

include_directories(${PROJECT_SOURCE_DIR}/code/buffer)
include_directories(${PROJECT_SOURCE_DIR}/code/http)
include_directories(${PROJECT_SOURCE_DIR}/code/log)
include_directories(${PROJECT_SOURCE_DIR}/code/pool)
include_directories(${PROJECT_SOURCE_DIR}/code/server)
include_directories(${PROJECT_SOURCE_DIR}/code/timer)


add_subdirectory(code)
add_subdirectory(demo)
