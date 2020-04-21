//
// Created by mingyi on 21.04.20.
//

#include <vector>
#include <cassert>

using namespace std;

vector<int> searchRange(vector<int> &nums, int target) {
  if (nums.empty()) {
    return vector<int> {-1, -1};
  }
  int left = 0, right = (int) nums.size() - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  if (nums[left] != target) {
    return vector<int> {-1, -1};
  }

  int first = left;
  right = (int) nums.size() - 1;
  while (left < right) {
    int mid = left + (right - left + 1) / 2;
    if (nums[mid] > target) {
      right = mid - 1;
    } else {
      left = mid;
    }
  }
  return vector<int> {first, right};
}

int main() {
  vector<int> nums1{5, 7, 7, 8, 8, 10};
  vector<int> expect1{3, 4};
  vector<int> result1 = searchRange(nums1, 8);
  for (int i = 0; i < nums1.size(); i++) {
    assert(expect1[i] == result1[i]);
  }
  return 0;
}