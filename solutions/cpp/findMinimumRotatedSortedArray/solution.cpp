//
// Created by mingyi on 21.04.20.
//

#include <vector>
#include <cassert>

using namespace std;

int findMin(vector<int> &nums) {
  int left = 0, right = (int) nums.size() - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] > nums[right]) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return nums[left];
}

int main() {
  vector<int> nums1{3, 4, 5, 1, 2};
  assert(1 == findMin(nums1));
  vector<int> nums2{4, 5, 6, 7, 0, 1, 2};
  assert(0 == findMin(nums2));
  return 0;
}