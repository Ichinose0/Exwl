#############################################################################
# Name:        CMakeLists.txt
# Purpose:     Primary CMake for Exwl
# Author:      Ichinose0
# Created:     2024-02-17
#############################################################################

cmake_minimum_required(VERSION 3.5)

set(exVERSION 1.0.0)

# Configuration for C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

include_directories(src/include)

set(exwl_SRC
    src/general.c
    src/native.c
    src/window.c
    src/win32_platform.c
    src/x11_platform.c

    src/include/internal.h
    src/include/platform.h

    include/Exwl/Exwl.h
    include/Exwl/native.h
)

project(Exwl VERSION ${exVERSION} DESCRIPTION "Extensible windowing library" LANGUAGES C CXX)

add_library(Exwl${exVERSION} SHARED ${exwl_SRC})
add_executable(window examples/window.c)
add_executable(cppsample examples/cppsample.cpp)

target_link_libraries(window Exwl${exVERSION})
target_link_libraries(cppsample Exwl${exVERSION})

target_include_directories(Exwl${exVERSION} INTERFACE ./include)