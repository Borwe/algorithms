cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(Algorithms)
add_executable(${PROJECT_NAME} src/main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)
