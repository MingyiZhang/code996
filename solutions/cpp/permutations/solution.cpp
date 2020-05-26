#include <vector>

using namespace std;

void backtracking(vector<int> &prefix, vector<bool> &visited, vector<int> &nums, vector<vector<int>> &ret) {
  if (prefix.size() == visited.size()) {
    ret.emplace_back(prefix);
    return;
  }
  for (int i = 0; i < visited.size(); i++) {
    if (visited[i]) {
      continue;
    }
    visited[i] = true;
    prefix.push_back(nums[i]);
    backtracking(prefix, visited, nums, ret);
    prefix.pop_back();
    visited[i] = false;
  }
}

vector<vector<int>> permute(vector<int> &nums) {
  vector<vector<int>> ret;
  vector<bool> visited(nums.size(), false);
  vector<int> prefix;
  backtracking(prefix, visited, nums, ret);
  return ret;
}