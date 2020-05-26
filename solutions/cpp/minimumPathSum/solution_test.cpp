//
// Created by mingyi on 26.05.20.
//


#include "gtest/gtest.h"

#include "solution.cpp"
#include "../include/structures.hpp"

using namespace std;
using namespace testing;

typedef TestStruct<vector<vector<int>>, int> TStruct;

class MinPathSumTest : public ::testing::TestWithParam<TStruct> {};

TEST_P(MinPathSumTest, Test) {
  TStruct tt = GetParam();
  int actual = minPathSum(tt.input);
  ASSERT_EQ(tt.expected, actual);
}

INSTANTIATE_TEST_SUITE_P(Tests, MinPathSumTest, ::testing::Values(
    TStruct{
        .input = vector<vector<int>>{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}},
        .expected = 7
    }
));