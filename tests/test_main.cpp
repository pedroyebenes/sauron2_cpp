// to compile g++ tests.cpp -lgtest -lgtest_main -pthread
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <stdio.h>
#include <string>

using namespace ::testing;

int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);

  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
