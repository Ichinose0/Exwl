#############################################################################
# Name:        CMakeLists.txt
# Purpose:     Primary CMake for Exwl
# Author:      Ichinose0
# Created:     2024-02-17
#############################################################################

cmake_minimum_required(VERSION 3.5)

set(exVERSION 1.0.0)

# Configuration for C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

include_directories(src/include)

set(exwl_SRC
    src/window.c
    src/win32_platform.c

    src/include/internal.h
    src/include/platform.h

    include/Exwl.h
)

project(Exwl VERSION ${exVERSION} DESCRIPTION "Extensible windowing library" LANGUAGES C)

add_library(Exwl${exVERSION} SHARED ${exwl_SRC})
add_executable(window main.c)
target_link_libraries(window Exwl${exVERSION})

target_include_directories(Exwl${exVERSION} INTERFACE ./include)
target_include_directories(window PRIVATE ./include)