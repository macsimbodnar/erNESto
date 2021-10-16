file(GLOB SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

add_executable(tmp ${SRCS})

target_link_libraries(tmp emu6502 pixello)
target_include_directories(tmp PRIVATE ../cpu/src/emu6502)
target_include_directories(tmp PRIVATE ../pixello/src)
