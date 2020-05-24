//
// Created by mingyi on 16.05.20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "solution.cpp"
#include "../include/structures.hpp"

using namespace std;
using namespace testing;

typedef TestStruct<vector<vector<char>>, vector<vector<char>>> TStruct;

class SurroundedRegionsTest
    : public ::testing::TestWithParam<TStruct> {
};

TEST_P(SurroundedRegionsTest, Test) {
  TStruct tt = GetParam();
  solve(tt.input);
  ASSERT_THAT(tt.input, ElementsAreArray(tt.expected));
}

INSTANTIATE_TEST_SUITE_P(Tests, SurroundedRegionsTest, ::testing::Values(
    TStruct{
        .input = {{'X', 'X', 'X', 'X'},
                  {'X', 'O', 'O', 'X'},
                  {'X', 'X', 'O', 'X'},
                  {'X', 'O', 'X', 'X'}},
        .expected = {{'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'X'},
                     {'X', 'O', 'X', 'X'}}
    },
    TStruct{
        .input = {{'X', 'O', 'X'},
                  {'X', 'O', 'X'},
                  {'X', 'O', 'X'}},
        .expected = {{'X', 'O', 'X'},
                     {'X', 'O', 'X'},
                     {'X', 'O', 'X'}}
    }
));
