cmake_minimum_required(VERSION 3.25)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_STANDARD 99)
SET(CMAKE_C_STANDARD_REQUIRED TRUE)
project(procoder VERSION 1.0.0 LANGUAGES C)

add_library(procoder SHARED )
target_compile_definitions(procoder PRIVATE PROCODER_EXPORTS)
add_subdirectory(cJSON)
add_subdirectory(procoder)
add_executable(codertest test/main.c)
target_link_libraries(codertest PRIVATE procoder)


