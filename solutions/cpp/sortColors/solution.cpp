//
// Created by mingyi on 18.04.20.
//

#include <vector>
#include <cassert>

using namespace std;

void sortColors(vector<int> &nums) {
  // nums[0...j-1] == 0, nums[j...i-1] == 1, nums[k+1...n-1] == 2
  int j = 0;
  int i = 0;
  int k = (int) nums.size() - 1;
  while (i <= k) {
    if (nums[i] == 0) {
      swap(nums[i], nums[j]);
      j++;
      i++;
    } else if (nums[i] == 1) {
      i++;
    } else {  // nums[i] == 2
      swap(nums[i], nums[k]);
      k--;
    }
  }
}

int main() {
  vector<int> input1 {2, 0, 2, 1, 1, 0};
  sortColors(input1);
  vector<int> expect1 {0, 0, 1, 1, 2, 2};
  for (int i = 0; i < input1.size(); i++) {
    assert(expect1[i] == input1[i]);
  }
  return 0;
}