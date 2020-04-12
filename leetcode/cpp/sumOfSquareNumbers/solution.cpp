//
// Created by mingyi on 12.04.20.
//

#include <cmath>
#include <cassert>

bool judgeSquareSum(int c) {
  long i = 0, j = std::sqrt(c);
  while (i <= j) {
    long s = i * i + j * j;
    if (s == c) return true;
    else if (s < c) i++;
    else j--;
  }
  return false;

// slow version
//  for (int b = (int) std::sqrt(c / 2); b <= (int) std::sqrt(c); b++) {
//    int a2 = c - b * b;
//    int a = (int) std::sqrt(a2);
//    if (a * a == a2) {
//      return true;
//    }
//  }
//  return false;

// slowest version
//  for (unsigned a = 0; a * a <= c; a++) {
//    double b = std::sqrt(c - a * a);
//    if ((unsigned) b == b) {
//      return true;
//    }
//  }
//  return false;
}

int main() {
  assert(judgeSquareSum(5));
  assert(judgeSquareSum(4));
  assert(!judgeSquareSum(3));
  assert(judgeSquareSum(2));
  assert(judgeSquareSum(16));
  return 0;
};
