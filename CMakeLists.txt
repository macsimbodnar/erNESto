cmake_minimum_required(VERSION 3.18)

project(erNESto)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(cpu)
add_subdirectory(pixello)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
