//
// Created by mingyi on 26.05.20.
//


#include "gtest/gtest.h"

#include "solution.cpp"
#include "../include/structures.hpp"

using namespace std;
using namespace testing;

typedef TestStruct<int, int> TStruct;

class ClimbStairsTest : public ::testing::TestWithParam<TStruct> {};

TEST_P(ClimbStairsTest, Test) {
  TStruct tt = GetParam();
  int actual = climbStairs(tt.input);
  ASSERT_EQ(tt.expected, actual);
}

INSTANTIATE_TEST_SUITE_P(Tests, ClimbStairsTest, ::testing::Values(
    TStruct{
        .input = 2,
        .expected = 2
    },
    TStruct{
        .input = 3,
        .expected = 3
    }
));