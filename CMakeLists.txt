cmake_minimum_required(VERSION 3.10.0)
project(testcv VERSION 0.1.0 LANGUAGES C CXX)

set(lib_name opencv)
add_library(${lib_name} INTERFACE)
target_include_directories(${lib_name} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE lib_files ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.lib)
target_link_libraries(${lib_name} INTERFACE ${lib_files})

set(exe_name testcv_exe)
add_executable(${exe_name} main/main.cpp)
target_link_libraries(${exe_name} PRIVATE opencv)