//
// Created by mingyi on 15.05.20.
//

#include <gtest/gtest.h>
#include <vector>

#include "solution.cpp"

using namespace std;

struct FindCircleNumTestStruct {
  vector<vector<int>> m;
  int expected;
};

class FindCircleNumTest : public ::testing::TestWithParam<FindCircleNumTestStruct> {};

TEST_P(FindCircleNumTest, Test) {
  FindCircleNumTestStruct tt = GetParam();
  ASSERT_EQ(tt.expected, findCircleNum(tt.m));
}

INSTANTIATE_TEST_SUITE_P(Tests, FindCircleNumTest, ::testing::Values(
    FindCircleNumTestStruct{
        .m = {{1, 1, 0},
              {1, 1, 0},
              {0, 0, 1}},
        .expected = 2
    },
    FindCircleNumTestStruct{
        .m = {{1, 1, 0},
              {1, 1, 1},
              {0, 1, 1}},
        .expected = 1
    },
    FindCircleNumTestStruct{
        .m = {{1, 0, 0, 1},
              {0, 1, 1, 0},
              {0, 1, 1, 1},
              {1, 0, 1, 1}},
        .expected = 1
    }
));
