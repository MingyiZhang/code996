//
// Created by mingyi on 14.05.20.
//

#include <vector>

using namespace std;

void dfs(int i, int I, vector<vector<int>> &M) {
  M[i][i] = 0;
  for (int j = 0; j < I; j++) {
    if (M[i][j]) {
      M[i][j] = 0;
      M[j][i] = 0;
      dfs(j, I, M);
    }
  }
}

int findCircleNum(vector<vector<int>> &M) {
  if (M.empty()) {
    return 0;
  }
  int ret = 0;
  int I = M.size();
  for (int i = 0; i < I; i++) {
    if (M[i][i]) {
      dfs(i, I, M);
      ret++;
    }
  }
  return ret;
}
