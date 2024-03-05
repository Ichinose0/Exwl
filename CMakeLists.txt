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

    src/include/internal.h
    src/include/platform.h

    include/Exwl/Exwl.h
)

if(WIN32)
set(exwl_PLATFROM_SRC src/win32_platform.c)
elseif(UNIX)
set(exwl_PLATFROM_SRC src/x11_platform.c)
endif()

project(Exwl VERSION ${exVERSION} DESCRIPTION "Extensible windowing library" LANGUAGES C CXX)

add_library(Exwl${exVERSION} SHARED ${exwl_SRC} ${exwl_PLATFROM_SRC})
add_executable(window examples/window.c)
add_executable(cppsample examples/cppsample.cpp)

if(UNIX)
find_package(X11 REQUIRED)

# Check if X11 was found
if (X11_FOUND)
    # Include directories
    include_directories(${X11_INCLUDE_DIR})
    
    # Link X11 library
    target_link_libraries(Exwl${exVERSION} ${X11_LIBRARIES})
else()
    message(FATAL_ERROR "X11 library not found")
endif()
endif()

target_link_libraries(window Exwl${exVERSION})
target_link_libraries(cppsample Exwl${exVERSION})

target_include_directories(Exwl${exVERSION} INTERFACE ./include)