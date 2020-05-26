//
// Created by mingyi on 26.05.20.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "solution.cpp"
#include "../include/structures.hpp"

using namespace std;
using namespace testing;

typedef TestStruct<tuple<vector<int>, int>, vector<vector<int>>> TStruct;

class CombinationSumTest : public ::testing::TestWithParam<TStruct> {};

TEST_P(CombinationSumTest, Test) {
  TStruct tt = GetParam();
  auto[candidates, target] = tt.input;
  vector<vector<int>> actual = combinationSum(candidates, target);
  ASSERT_THAT(actual, UnorderedElementsAreArray(tt.expected));
}

INSTANTIATE_TEST_SUITE_P(Tests, CombinationSumTest, ::testing::Values(
    TStruct{
        .input = make_tuple(vector<int>{2, 3, 6, 7}, 7),
        .expected = {{7}, {2, 2, 3}}
    },
    TStruct{
        .input = make_tuple(vector<int>{2, 3, 5}, 8),
        .expected = {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}}
    }
));
