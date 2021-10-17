file(GLOB SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

add_executable(erNEStop ${SRCS})

target_link_libraries(erNEStop emu6502 pixello)
target_include_directories(erNEStop PRIVATE ../cpu/src/emu6502)
target_include_directories(erNEStop PRIVATE ../pixello/src)
