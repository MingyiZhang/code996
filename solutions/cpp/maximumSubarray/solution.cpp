//
// Created by mingyi on 20.04.20.
//

#include <vector>
#include <limits>
#include <cassert>

using namespace std;

int maxSubArray(vector<int> &nums) {
  int preSum = 0;
  int maxSum = numeric_limits<int>::min();
  for (int x : nums) {
    preSum = preSum > 0 ? preSum + x : x;
    maxSum = max(maxSum, preSum);
  }
  return maxSum;
}

int main() {
  vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  assert(6 == maxSubArray(nums));
  return 0;
}