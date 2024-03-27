cmake_minimum_required (VERSION 3.2)
project(MD)


FILE(GLOB SOURCE_FILES src/*.c src/scenes/*.c src/math/*.c)

add_executable(main ${SOURCE_FILES} )

find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
	target_link_libraries(main PUBLIC ${MATH_LIBRARY})
endif()
#src/main.c src/mainScene.c src/nwdScene.c src/nwd_nww.c src/menu.c src/gui.c src/utils.c
