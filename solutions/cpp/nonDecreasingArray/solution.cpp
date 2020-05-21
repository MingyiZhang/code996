//
// Created by mingyi on 20.04.20.
//

#include <vector>
#include <cassert>

using namespace std;

bool checkPossibility(vector<int> &nums) {
// concise but not faster
//  int cnt = 0;
//  for (int i = 1; i < nums.size() && cnt <= 1; i++) {
//    if (nums[i - 1] > nums[i]) {
//      if (i >= 2 && nums[i - 2] > nums[i]) {
//        nums[i] = nums[i - 1];
//      } else {
//        nums[i - 1] = nums[i];
//      }
//      cnt++;
//    }
//  }
//  return cnt <= 1;

  int cnt = 0;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i - 1] <= nums[i]) {
      continue;
    }

    if (i >= 2 && nums[i - 2] > nums[i]) {
      nums[i] = nums[i - 1];
    } else {
      nums[i - 1] = nums[i];
    }

    cnt++;
    if (cnt > 1) {
      return false;
    }
  }
  return true;
}

int main() {
  vector<int> nums1{4, 2, 3};
  vector<int> nums2{4, 2, 1};
  vector<int> nums3{3, 4, 2, 3};
  assert(checkPossibility(nums1));
  assert(!checkPossibility(nums2));
  assert(!checkPossibility(nums3));
}