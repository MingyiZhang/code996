#include <vector>
#include <algorithm>

using namespace std;

void backtracking(vector<int> &prefix,
                  int preSum,
                  vector<int> &candidates,
                  int index,
                  int target,
                  vector<vector<int>> &ret) {
  if (preSum == target && !prefix.empty()) {
    ret.emplace_back(prefix);
    return;
  }

  for (int i = index; i < candidates.size(); i++) {
    if (preSum + candidates[i] <= target) {
      preSum += candidates[i];
      prefix.push_back(candidates[i]);
      backtracking(prefix, preSum, candidates, i, target, ret);
      prefix.pop_back();
      preSum -= candidates[i];
    } else {
      break;
    }
  }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector<vector<int>> ret;
  vector<int> prefix;
  backtracking(prefix, 0, candidates, 0, target, ret);
  return ret;
}