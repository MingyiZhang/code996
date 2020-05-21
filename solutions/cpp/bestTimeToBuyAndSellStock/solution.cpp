//
// Created by mingyi on 20.04.20.
//

#include <vector>
#include <limits>
#include <cassert>

using namespace std;

int maxProfit(vector<int> &prices) {
  int lowest{numeric_limits<int>::max()};
  int ret{0};
  for (const auto &p : prices) {
    if (p > lowest) {
      ret = max(ret, p - lowest);
    } else {
      lowest = p;
    }
  }
  return ret;
}

int main() {
  vector<int> prices1{7, 1, 5, 3, 6, 4};
  assert(5 == maxProfit(prices1));
  vector<int> prices2{7, 6, 4, 3, 1};
  assert(0 == maxProfit(prices2));

  return 0;
}