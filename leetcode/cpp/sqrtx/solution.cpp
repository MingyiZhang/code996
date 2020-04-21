//
// Created by mingyi on 21.04.20.
//

#include <cassert>

using namespace std;

int mySqrt(int x) {
  if (x <= 1) {
    return x;
  }

  int left = 1, right = x;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    int sqrt = x / mid;
    if (sqrt == mid) {
      return mid;
    } else if (sqrt < mid) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return right;
}

int main() {
  assert(2 == mySqrt(4));
  assert(2 == mySqrt(8));
}

