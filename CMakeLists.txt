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
if(MSVC)
    target_compile_definitions(stack PUBLIC DYNAMIC_DLL)
endif()
# stack_test1
#add_executable(stack_test1 src/stack_test.cpp)
#target_link_libraries(stack_test1 PUBLIC stack)

#setup the library to be used for reading data
# setup for boost algos header files
find_package(Boost 1.67)
include_directories(${Boost_INCLUDE_DIRS})
add_library(data_handler SHARED src/data_handler.cpp)
if(MSVC)
    target_compile_definitions(data_handler PUBLIC DYNAMIC_DLL)
endif()
add_executable(data_handler_test src/data_handler_test.cpp)
target_link_libraries(data_handler_test PUBLIC data_handler)


#for cmake compile_commands.json generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
  )
ENDIF()
