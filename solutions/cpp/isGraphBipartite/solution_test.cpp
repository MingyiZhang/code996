//
// Created by mingyi on 07.06.20.
//


#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "solution.cpp"
#include "../include/structures.hpp"

using namespace std;
using namespace testing;

typedef TestStruct<vector<vector<int>>, bool> TStruct;

class IsBipartiteTest : public ::testing::TestWithParam<TStruct> {};

TEST_P(IsBipartiteTest, Test
) {
  TStruct tt = GetParam();
  bool actual = isBipartite(tt.input);
  ASSERT_EQ(tt.expected, actual);
}

INSTANTIATE_TEST_SUITE_P(Tests, IsBipartiteTest, ::testing::Values(
    TStruct{
        .input = {{1, 3}, {0, 2}, {1, 3}, {0, 2}},
        .expected = true,
    },
    TStruct{
        .input = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}},
        .expected = false,
    },
    TStruct{
        .input = {{3}, {2, 4}, {1}, {0, 4}, {1, 3}},
        .expected = true,
    }
)
);