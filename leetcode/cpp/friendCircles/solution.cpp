//
// Created by mingyi on 14.05.20.
//

#include <vector>
#include <cassert>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int i, int j, int I, int J, vector<vector<int>> &M) {
  if (i < 0 || i >= I || j < 0 || j >= J || !M[i][j]) {
    return;
  }
  M[i][j] = 0;
  for (int k = 0; k < 4; k++) {
    dfs(i + dx[k], j + dy[k], I, J, M);
  }
}

int findCircleNum(vector<vector<int>> &M) {
  if (M.empty()) {
    return 0;
  }
  int ret = 0;
  int I = M.size(), J = M[0].size();
  for (int i = 0; i < I; i++) {
    for (int j = 0; j < J; j++) {
      if (M[i][j]) {
        dfs(i, j, I, J, M);
        ret++;
      }
    }
  }
  return ret;
}

struct Test {
  vector<vector<int>> m;
  int ans;
};

int main() {
  vector<Test> tests{
      {
          .m = {{1, 1, 0},
                {1, 1, 0},
                {0, 0, 1}},
          .ans = 2
      },
      {
          .m = {{1, 1, 0},
                {1, 1, 1},
                {0, 1, 1}},
          .ans = 1
      }
  };
  for (auto &tt : tests) {
    int actual = findCircleNum(tt.m);
    assert(tt.ans == actual);
  }
  return 0;
}