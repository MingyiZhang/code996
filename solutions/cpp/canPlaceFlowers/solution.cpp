//
// Created by mingyi on 20.04.20.
//

#include <vector>
#include <cassert>

using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n) {
  int end = (int) flowerbed.size() - 1;
  for (int i = 0; i < flowerbed.size(); i++) {
    if (!n) {
      return true;
    }
    if (!flowerbed[i] && (i == 0 or !flowerbed[i - 1]) && (i == end or !flowerbed[i + 1])) {
      flowerbed[i] = 1;
      n--;
    }
  }
  return !n;
}

int main() {
  vector<int> f1 {1, 0, 0, 0, 1};
  assert(canPlaceFlowers(f1, 1));
  assert(!canPlaceFlowers(f1, 2));
  vector<int> f2 {0, 0, 1, 0, 0};
  assert(canPlaceFlowers(f2, 1));
  vector<int> f3 {0, 0, 0, 1, 0};
  assert(canPlaceFlowers(f3, 0));
  return 0;
}