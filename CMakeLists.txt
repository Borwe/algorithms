#Copyright (C) 2021  Brian Orwe
#
#This program is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.
#
#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with this program.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.10)

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
    if(CMAKE_CXX_COMPILER_ID STREQUAL GNU)
        if(CMAKE_COMPILER_VERSION VERSION_LESS 8)
            find_package(Boost 1.65 COMPONENTS REQUIRED filesystem system)
            target_link_libraries(data_handler PUBLIC Boost::filesystem Boost::system)
            message(STATUS "Good old Gcc being used")
        endif()
    endif()
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        message("-- Nice, cool kids use clang")
        target_compile_options(data_handler PUBLIC  "-stdlib=libc++")
        link_libraries(-lc++abi -lc++)
    endif()
endif()
add_executable(data_handler_test src/data_handler_test.cpp)
target_link_libraries(data_handler_test PUBLIC data_handler)

# hold data object info
add_library(data SHARED src/data/date.cpp src/data/transaction.cpp)

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

#ex1.3.15
add_executable(ex1.3.15 src/ex1.3.15.cpp)

#ex1.3.16
add_executable(ex1.3.16 src/ex1.3.16.cpp)
target_link_libraries(ex1.3.16 PUBLIC data)

#ex1.3.17
add_executable(ex1.3.17 src/ex1.3.17.cpp)
target_link_libraries(ex1.3.17 PUBLIC data)

#for cmake compile_commands.json generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
  )
ENDIF()
