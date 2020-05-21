//
// Created by mingyi on 16.04.20.
//

#include <vector>
#include <cassert>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
  int i = m - 1, j = n - 1;
  for (int k = m + n - 1; k >= 0; k--) {
    if (i < 0) {
      nums1[k] = nums2[j--];
    } else if (j < 0) {
      nums1[k] = nums1[i--];
    } else if (nums1[i] > nums2[j]) {
      nums1[k] = nums1[i--];
    } else {
      nums1[k] = nums2[j--];
    }
  }
}


int main() {
  vector<int> nums1 {1, 2, 3, 0, 0, 0};
  vector<int> nums2 {2, 5 ,6};
  int m = 3, n = 3;
  merge(nums1, m, nums2, n);
  vector<int> expect {1, 2, 2, 3, 5, 6};
  for (int i = 0; i < nums1.size(); i++) {
    assert(expect[i] == nums1[i]);
  }
  return 0;
}