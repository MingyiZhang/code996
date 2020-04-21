//
// Created by mingyi on 21.04.20.
//

#include <cassert>

bool isBadVersion(int version) {
  return version > 3;
}

int firstBadVersion(int n) {
  int left = 1, right = n;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (isBadVersion(mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

int main() {
  assert(4 == firstBadVersion(10));
  return 0;
}