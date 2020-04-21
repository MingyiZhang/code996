//
// Created by mingyi on 21.04.20.
//

#include <vector>
#include <cassert>

using namespace std;

int singleNonDuplicate(vector<int> &nums) {
  int left = 0, right = (int) nums.size() - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
      return nums[mid];
    } else if (nums[mid] == nums[mid + 1]) {
      if ((right - mid) % 2) {  // [mid+1...right] is odd
        right = mid - 1;
      } else { // [mid+1...right] is even
        left = mid + 2;
      }
    } else if (nums[mid - 1] == nums[mid]) {
      if ((mid - left) % 2) {  // [left...mid-1] is odd
        left = mid + 1;
      } else {  // [left...mid-1] is even
        right = mid - 2;
      }
    }
  }
  return nums[left];
}


// binary bitwise operator version
int singleNonDuplicateBitOp(vector<int> &nums) {
  int ans = 0;
  for (int x : nums) {
    ans ^= x;
  }
  return ans;
}


int main() {
  vector<int> nums1 {1, 1, 2, 3, 3, 4, 4, 8, 8};
  assert (2 == singleNonDuplicate(nums1));
  assert (2 == singleNonDuplicateBitOp(nums1));
  vector<int> nums2 {3, 3, 7, 7, 10, 11, 11};
  assert (10 == singleNonDuplicate(nums2));
  assert (10 == singleNonDuplicateBitOp(nums2));
  return 0;
}