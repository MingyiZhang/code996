#include <vector>
#include <climits>

using namespace std;

int minPathSum(vector<vector<int>> &grid) {
  if (grid.empty()) {
    return 0;
  }
  int m = grid.size(), n = grid[0].size();
  vector<vector<int>> values(m, vector<int>(n, INT_MAX));
  values[0][0] = grid[0][0];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i > 0) {
        values[i][j] = min(values[i][j], values[i - 1][j] + grid[i][j]);
      }
      if (j > 0) {
        values[i][j] = min(values[i][j], values[i][j - 1] + grid[i][j]);
      }
    }
  }
  return values[m - 1][n - 1];
}