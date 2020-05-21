
#include <vector>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int i, int j, int I, int J, vector<vector<char>> &board) {
  if (i < 0 || i >= I || j < 0 || j >= J || board[i][j] != 'O') {
    return;
  }
  board[i][j] = 'B';
  for (int k = 0; k < 4; k++) {
    dfs(i + dx[k], j + dy[k], I, J, board);
  }
}

void solve(vector<vector<char>> &board) {
  if (board.empty()) {
    return;
  }
  int I = board.size(), J = board[0].size();
  // find all O nodes attach to the boundary, and replace with B
  for (int i = 0; i < I; i++) {
    dfs(i, 0, I, J, board);
    dfs(i, J - 1, I, J, board);
  }
  for (int j = 1; j < J - 1; j++) {
    dfs(0, j, I, J, board);
    dfs(I - 1, j, I, J, board);
  }

  // replace O with X, B with O
  for (int i = 0; i < I; i++) {
    for (int j = 0; j < J; j++) {
      if (board[i][j] == 'O') {
        board[i][j] = 'X';
      } else if (board[i][j] == 'B') {
        board[i][j] = 'O';
      }
    }
  }
}

