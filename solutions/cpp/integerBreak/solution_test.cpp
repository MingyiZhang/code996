//
// Created by mingyi on 26.05.20.
//


#include "gtest/gtest.h"

#include "solution.cpp"
#include "../include/structures.hpp"

using namespace std;
using namespace testing;

typedef TestStruct<int, int> TStruct;

class IntegerBreakTest : public ::testing::TestWithParam<TStruct> {};

TEST_P(IntegerBreakTest, Test
) {
  TStruct tt = GetParam();
  int actual = integerBreak(tt.input);
  ASSERT_EQ(tt
                .expected, actual);
}

INSTANTIATE_TEST_SUITE_P(Tests, IntegerBreakTest, ::testing::Values(
    TStruct{
        .input = 2,
        .expected =1
    },
    TStruct{
        .input = 10,
        .expected = 36
    }
)
);