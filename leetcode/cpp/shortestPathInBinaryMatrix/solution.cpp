//
// Created by mingyi on 23.04.20.
//

#include <vector>
#include <queue>
#include <cassert>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
  int N = grid.size();
  if (!N || grid[0][0] || grid[N - 1][N - 1]) {
    return -1;
  }
  if (N == 1) {
    return 1;
  }
  queue<pair<int, int>> q;
  q.push({0, 0});
  grid[0][0] = 1;
  int pathLength = 1;
  while (!q.empty()) {
    pathLength++;
    int qSize = q.size();
    while (qSize--) {
      pair<int, int> p = q.front();
      q.pop();
      int x0 = p.first;
      int y0 = p.second;
      for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
          if (!i && !j) {
            continue;
          }
          int x = x0 + i;
          int y = y0 + j;
          if (x == N - 1 && y == N - 1) {
            return pathLength;
          }
          if (x >= 0 && y >= 0 && x < N && y < N && !grid[x][y]) {
            grid[x][y] = 1;
            q.push({x, y});
          }
        }
      }
    }
  }
  return -1;
}

int main() {
  vector<vector<int>> grid1{{0, 1}, {1, 0}};
  assert(2 == shortestPathBinaryMatrix(grid1));
  vector<vector<int>> grid2{{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  assert(4 == shortestPathBinaryMatrix(grid2));
  vector<vector<int>> grid3{{0}};
  assert(1 == shortestPathBinaryMatrix(grid3));
  return 0;
}