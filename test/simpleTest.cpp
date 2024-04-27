#include <gtest/gtest.h>

extern "C" {
	#include "nwd_nww.h"
}

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(HelloTest, BasicPow) {
  // Expect two strings not to be equal.
  // Expect equality.
  EXPECT_EQ(fastPow(2,2), 4);
  EXPECT_EQ(fastPow(2,10), 1024);
}
