//
// Created by mingyi on 15.05.20.
//

#include <gtest/gtest.h>
#include <vector>

#include "solution.cpp"
#include "../include/structures.hpp"

using namespace std;

typedef TestStruct<vector<vector<int>>, int> TStruct;

class MaxAreaOfIslandTest : public ::testing::TestWithParam<TStruct> {};

TEST_P(MaxAreaOfIslandTest, Test) {
  TStruct tt = GetParam();
  ASSERT_EQ(tt.expected, maxAreaOfIsland(tt.input));
}

INSTANTIATE_TEST_SUITE_P (Tests, MaxAreaOfIslandTest, ::testing::Values(
    TStruct{
        .input = {{0, 1, 0},
                  {1, 0, 1},
                  {0, 1, 1}},
        .expected = 3
    },
    TStruct{
        .input =   {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                    {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                    {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}},
        .expected = 6
    },
    TStruct{
        .input = {{0, 0, 0, 0, 0}},
        .expected = 0
    })
);