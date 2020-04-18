//
// Created by mingyi on 18.04.20.
//

#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &intervals) {
  if (intervals.empty()) {
    return 0;
  }

  sort(intervals.begin(), intervals.end(), [](const vector<int> &itv1, const vector<int> &itv2) {
    return itv1[1] < itv2[1];
  });

  int cnt = 0;
  int end = intervals[0][1];
  for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] < end) {
      cnt++;
    } else {
      end = intervals[i][1];
    }
  }
  return cnt;
}

int main() {
  vector<vector<int>> intervals1 {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  assert(1 == eraseOverlapIntervals(intervals1));
  vector<vector<int>> intervals2 {{1, 2}, {1, 2}, {1, 2}};
  assert(2 == eraseOverlapIntervals(intervals2));
  vector<vector<int>> intervals3 {{1, 2}, {2, 3}};
  assert(0 == eraseOverlapIntervals(intervals3));
  vector<vector<int>> intervals4 {{0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}};
  assert(2 == eraseOverlapIntervals(intervals4));
  return 0;
}

