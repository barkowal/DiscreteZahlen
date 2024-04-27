cmake_minimum_required (VERSION 3.27.2)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project(MD)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#TESTING
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
#TESTING


#MAIN
add_subdirectory(src)

add_executable(main main.c)
target_link_libraries(main PRIVATE gui)

find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
	target_link_libraries(main PUBLIC ${MATH_LIBRARY})
endif()
#MAIN


add_subdirectory(test)
