//
// Created by mingyi on 07.06.20.
//


#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "solution.cpp"
#include "../include/structures.hpp"

using namespace std;
using namespace testing;

typedef TestStruct<tuple<int, vector<vector<int>>>, bool> TStruct;

class CanFinishTest : public ::testing::TestWithParam<TStruct> {};

TEST_P(CanFinishTest, Test
) {
  TStruct tt = GetParam();
  auto[numCourses, prerequisites] = tt.input;
  bool actual = canFinish(numCourses, prerequisites);
  ASSERT_EQ(tt.expected, actual);
}

INSTANTIATE_TEST_SUITE_P(Tests, CanFinishTest, ::testing::Values(
    TStruct{
        .input = make_tuple<int, vector<vector<int>>>(2, {{1, 0}}),
        .expected = true
    },
    TStruct{
        .input = make_tuple<int, vector<vector<int>>>(2, {{1, 0}, {0, 1}}),
        .expected = false
    }
)
);