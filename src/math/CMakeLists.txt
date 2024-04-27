FILE(GLOB mathSources *.c)
add_library(md_math "${mathSources}")
target_include_directories(md_math PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
