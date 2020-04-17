//
// Created by mingyi on 17.04.20.
//

#include <vector>
#include <ctime>
#include <cstdlib>
#include <cassert>

using namespace std;

int partition(vector<int> &nums, int l, int r) {
  int rd = rand() % (r - l + 1) + l;
  swap(nums[rd], nums[l]);
  int v = nums[l];
  // nums[l+1...j] > v, nums[j+1...i-1] <= v
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (nums[i] > v) {
      swap(nums[i], nums[j + 1]);
      j++;
    }
  }
  swap(nums[l], nums[j]);
  return j;
}


int findKthLargestImpl(vector<int> &nums, int k, int l, int r) {
  int p = partition(nums, l, r);
  int kIdx = k - 1;
  if (p == kIdx) {
    return nums[p];
  } else if (p < kIdx) {
    return findKthLargestImpl(nums, k, p + 1, r);
  } else {
    return findKthLargestImpl(nums, k, l, p - 1);
  }
}


int findKthLargest(vector<int> &nums, int k) {
  return findKthLargestImpl(nums, k, 0, nums.size() - 1);
}

int main() {
  srand(time(nullptr));
  vector<int> nums1 {3, 2, 1, 5, 6, 4};
  int k1 {2};
  assert(5 == findKthLargest(nums1, k1));
  vector<int> nums2 {3, 2, 3, 1, 2, 4, 5, 5, 6};
  int k2 {4};
  assert(4 == findKthLargest(nums2, k2));
  return 0;
}