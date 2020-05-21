//
// Created by mingyi on 20.04.20.
//

#include <vector>
#include <limits>
#include <cassert>

using namespace std;

int maxProfit(vector<int> &prices) {
  int profit{0};
  for (int i = 1; i < prices.size(); i++) {
    if (prices[i] > prices[i - 1]) {
      profit += prices[i] - prices[i - 1];
    }
  }
  return profit;
}

int main() {
  vector<int> prices1{7, 1, 5, 3, 6, 4};
  assert(7 == maxProfit(prices1));
  vector<int> prices2{7, 6, 4, 3, 1};
  assert(0 == maxProfit(prices2));
  vector<int> prices3{1, 2, 3, 4, 5};
  assert(4 == maxProfit(prices3));
  return 0;
}