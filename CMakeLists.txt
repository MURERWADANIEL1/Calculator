cmake_minimum_required(VERSION 3.10)
project(Calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Collect module sources
file(GLOB MODULE_SRCS "${CMAKE_SOURCE_DIR}/modules/*.cpp")

add_executable(calculator
    ${CMAKE_SOURCE_DIR}/SimpleCalculator.cpp
    ${MODULE_SRCS}
)

# Include project root so headers in modules/ can be included with "modules/xxx.h"
target_include_directories(calculator PRIVATE ${CMAKE_SOURCE_DIR})

# Compiler warnings
if (MSVC)
    target_compile_options(calculator PRIVATE /W4 /permissive-)
else()
    target_compile_options(calculator PRIVATE -Wall -Wextra -Wpedantic)
endif()
