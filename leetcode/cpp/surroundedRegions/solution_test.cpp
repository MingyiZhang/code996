//
// Created by mingyi on 16.05.20.
//

#include <gtest/gtest.h>

#include "solution.cpp"

using namespace std;

struct SurroundedRegionsTestStruct {
  vector<vector<char>> board;
  vector<vector<char>> expected;
};

class SurroundedRegionsTest
    : public ::testing::TestWithParam<SurroundedRegionsTestStruct> {
};

TEST_P(SurroundedRegionsTest, Test) {
  SurroundedRegionsTestStruct tt = GetParam();
  solve(tt.board);
  for (int i = 0; i < tt.board.size(); i++) {
    for (int j = 0; j < tt.board[0].size(); j++) {
      EXPECT_EQ(tt.expected[i][j], tt.board[i][j])
                << "expected board and actual board differ at index " << i << " and " << j << '\n';
    }
  }
}

INSTANTIATE_TEST_SUITE_P(Tests, SurroundedRegionsTest, ::testing::Values(
    SurroundedRegionsTestStruct{
        .board = {{'X', 'X', 'X', 'X'},
                  {'X', 'O', 'O', 'X'},
                  {'X', 'X', 'O', 'X'},
                  {'X', 'O', 'X', 'X'}},
        .expected = {{'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'X'},
                     {'X', 'O', 'X', 'X'}}
    },
    SurroundedRegionsTestStruct{
        .board = {{'X', 'O', 'X'},
                  {'X', 'O', 'X'},
                  {'X', 'O', 'X'}},
        .expected = {{'X', 'O', 'X'},
                     {'X', 'O', 'X'},
                     {'X', 'O', 'X'}}
    }
));
