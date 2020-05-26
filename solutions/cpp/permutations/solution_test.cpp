//
// Created by mingyi on 25.05.20.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "solution.cpp"
#include "../include/structures.hpp"

using namespace std;
using namespace testing;

typedef TestStruct<vector<int>, vector<vector<int>>> TStruct;

class PermutationTest : public ::testing::TestWithParam<TStruct> {};

TEST_P(PermutationTest, Test) {
  TStruct tt = GetParam();
  vector<vector<int>> actual = permute(tt.input);
  ASSERT_THAT(actual, UnorderedElementsAreArray(tt.expected));
}

INSTANTIATE_TEST_SUITE_P(Tests, PermutationTest, ::testing::Values(
    TStruct{
        .input = {1, 2, 3},
        .expected = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                     {2, 3, 1}, {3, 1, 2}, {3, 2, 1}}
    }
));
