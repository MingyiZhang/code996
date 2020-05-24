//
// Created by mingyi on 15.05.20.
//

#include <gtest/gtest.h>
#include <vector>

#include "solution.cpp"
#include "../include/structures.hpp"

using namespace std;

typedef TestStruct<vector<vector<int>>, int> TStruct;

class FindCircleNumTest : public ::testing::TestWithParam<TStruct> {};

TEST_P(FindCircleNumTest, Test) {
  TStruct tt = GetParam();
  ASSERT_EQ(tt.expected, findCircleNum(tt.input));
}

INSTANTIATE_TEST_SUITE_P(Tests, FindCircleNumTest, ::testing::Values(
    TStruct{
        .input = {{1, 1, 0},
                  {1, 1, 0},
                  {0, 0, 1}},
        .expected = 2
    },
    TStruct{
        .input = {{1, 1, 0},
                  {1, 1, 1},
                  {0, 1, 1}},
        .expected = 1
    },
    TStruct{
        .input = {{1, 0, 0, 1},
                  {0, 1, 1, 0},
                  {0, 1, 1, 1},
                  {1, 0, 1, 1}},
        .expected = 1
    }
));
