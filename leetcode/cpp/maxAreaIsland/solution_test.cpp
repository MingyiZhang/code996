//
// Created by mingyi on 15.05.20.
//

#include <gtest/gtest.h>
#include <vector>

#include "solution.cpp"

using namespace std;

struct MaxAreaOfIslandTestStruct {
  vector<vector<int>> grid;
  int expected;
};

class MaxAreaOfIslandTest : public ::testing::TestWithParam<MaxAreaOfIslandTestStruct> {};

TEST_P(MaxAreaOfIslandTest, Test) {
  MaxAreaOfIslandTestStruct tt = GetParam();
  ASSERT_EQ(tt.expected, maxAreaOfIsland(tt.grid));
}

INSTANTIATE_TEST_SUITE_P (Tests, MaxAreaOfIslandTest, ::testing::Values(
    MaxAreaOfIslandTestStruct{
        .grid = {{0, 1, 0},
                 {1, 0, 1},
                 {0, 1, 1}},
        .expected = 3
    },
    MaxAreaOfIslandTestStruct{
        .grid =   {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}},
        .expected = 6
    },
    MaxAreaOfIslandTestStruct{
        .grid = {{0, 0, 0, 0, 0}},
        .expected = 0
    })
);