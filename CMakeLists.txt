cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(Algos)
# setup include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# setup an executable
add_executable(${PROJECT_NAME} src/main.cpp)

#setup stacks library
add_library(stack SHARED src/stack.cpp)

# stack_test1
add_executable(stack_test1 src/stack_test.cpp)
target_link_libraries(stack_test1 PUBLIC stack)

#setup the library to be used for reading data
add_library(data_handler SHARED src/data_handler.cpp)
add_executable(data_handler_test src/data_handler_test.cpp)
target_link_libraries(data_handler_test PUBLIC data_handler)
