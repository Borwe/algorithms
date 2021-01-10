cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(Algos)
# setup include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# setup an executable
add_executable(${PROJECT_NAME} src/main.cpp)

# setup the library to be used for reading data
# setup for boost algos header files
find_package(Boost 1.65)
include_directories(${Boost_INCLUDE_DIRS})
add_library(data_handler SHARED src/data_handler.cpp
    src/custom_vals.cpp)
if(MSVC)
    target_compile_definitions(data_handler PUBLIC DYNAMIC_DLL)
endif()
if(UNIX)
    message("-- Using Uinx")
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GCC")
        if(CMAKE_COMPILER_VERSION VERSION_LESS 8.0)
            find_package(Boost 1.65 COMPONENTS REQUIRED filesystem)
            target_link_libraries(data_handler PUBLIC Boost::filesystem)
        endif()
    endif()
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        message("-- Nice, cool kids use clang")
        target_compile_options(data_handler PUBLIC  "-stdlib=libc++")
        add_link_options(-lc++abi -lc++)
    endif()
endif()
add_executable(data_handler_test src/data_handler_test.cpp)
target_link_libraries(data_handler_test PUBLIC data_handler)

# stack_test1
add_executable(stack_test1 src/stack_test.cpp)
target_link_libraries(stack_test1 PUBLIC data_handler)

#queue_test1
add_executable(queue_test1 src/queue_test.cpp)
target_link_libraries(queue_test1 PUBLIC data_handler)

#ex1.3.3
add_executable(ex1.3.3 src/ex1.3.3.cpp)
target_link_libraries(ex1.3.3 PUBLIC data_handler)

#ex1.3.4
add_executable(ex1.3.4 src/ex1.3.4.cpp)
target_link_libraries(ex1.3.4 PUBLIC data_handler)

#ex1.3.9
add_executable(ex1.3.9 src/ex1.3.9.cpp)

#ex1.3.12
add_executable(ex1.3.12 src/ex1.3.12.cpp)

#ex1.3.13
add_executable(ex1.3.13 src/ex1.3.13.cpp)
target_link_libraries(ex1.3.13 PUBLIC data_handler)

#for cmake compile_commands.json generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
  )
ENDIF()
