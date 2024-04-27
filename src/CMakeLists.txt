FILE(GLOB SOURCE_FILES *.c
scenes/*.c 
scenes/congruence/*.c
scenes/other/*.c
scenes/games/*.c
scenes/games/snake/*.c
)

add_subdirectory(math)

add_library(gui "${SOURCE_FILES}")
target_link_libraries(gui PRIVATE md_math)
target_include_directories(gui PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/math/include")

