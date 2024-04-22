cmake_minimum_required (VERSION 3.27.2)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project(MD)


FILE(GLOB SOURCE_FILES src/*.c
src/scenes/*.c 
src/scenes/congruence/*.c
src/scenes/other/*.c
src/math/*.c)

add_executable(main ${SOURCE_FILES} )

find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
	target_link_libraries(main PUBLIC ${MATH_LIBRARY})
endif()
