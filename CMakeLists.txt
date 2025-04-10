cmake_minimum_required(VERSION 3.10.0)
project(testcv VERSION 0.1.0 LANGUAGES C CXX)


set(plf_path "${CMAKE_CURRENT_SOURCE_DIR}/opencv_builds")
if (WIN32)
set(plf_path "${plf_path}/windows-amd64-static")
elseif (UNIX AND NOT APPLE)
set(plf_path "${plf_path}/linux")
elseif (APPLE)
set(plf_path "${plf_path}/macos")
endif()

set(lib_name opencv)
add_library(${lib_name} INTERFACE)
target_include_directories(${lib_name} INTERFACE ${plf_path}/include)
file(GLOB_RECURSE lib_files ${plf_path}/lib/*.lib)
target_link_libraries(${lib_name} INTERFACE ${lib_files})

set(exe_name testcv_exe)
add_executable(${exe_name} main/main.cpp)
set_target_properties(${exe_name} PROPERTIES COMPILE_FLAGS "/MT")
target_link_libraries(${exe_name} PRIVATE opencv)