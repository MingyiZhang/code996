//
// Created by mingyi on 17.04.20.
//

#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k) {
  // count
  unordered_map<int, int> freqMap;
  for (const auto &num : nums) {
    freqMap[num]++;
  }
  // heapify
  priority_queue<pair<int, int>> freqPQ;
  for (const auto p : freqMap) {
    freqPQ.push({p.second, p.first});
  }

  // get top K
  vector<int> ret;
  for (int i = 0; i < k; i++) {
    ret.push_back(freqPQ.top().second);
    freqPQ.pop();
  }
  return ret;
}

int main() {
  vector<int> nums1 {1, 1, 1, 2, 2, 3};
  int k1 {2};
  vector<int> result1 = topKFrequent(nums1, k1);
  for (const auto &v : result1) {
    cout << v << ' ';
  }
  return 0;
}