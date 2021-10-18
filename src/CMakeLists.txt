file(GLOB SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

add_executable(erNESto ${SRCS})

target_link_libraries(erNESto emu6502 pixello)
target_include_directories(erNESto PRIVATE ../cpu/src/emu6502)
target_include_directories(erNESto PRIVATE ../pixello/src)
