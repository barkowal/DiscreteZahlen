file(GLOB SOURCES *.cpp)
add_executable(
  math_test
  ${SOURCES}
)

target_link_libraries(
  math_test
  PRIVATE md_math
  PRIVATE gui
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(math_test)
