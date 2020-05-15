//
// Created by mingyi on 09.05.20.
//

#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int area(int i, int j, int I, int J, vector<vector<int>> &grid) {
  if (i < 0 || j < 0 || i >= I || j >= J || !grid[i][j]) {
    return 0;
  }
  grid[i][j] = 0;
  int ret = 1;
  for (int k = 0; k < 4; k++) {
    ret += area(i + dx[k], j + dy[k], I, J, grid);
  }
  return ret;
}

int maxAreaOfIsland(vector<vector<int>> &grid) {
  if (grid.empty()) {
    return 0;
  }
  int ret{0};
  const int I = grid.size(), J = grid[0].size();
  for (int i = 0; i < I; i++) {
    for (int j = 0; j < J; j++) {
      if (grid[i][j]) {
        ret = max(area(i, j, I, J, grid), ret);
      }
    }
  }
  return ret;
}
