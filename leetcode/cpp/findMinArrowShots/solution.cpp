//
// Created by mingyi on 19.04.20.
//

#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int findMinArrowShots(vector<vector<int>> &points) {
  if (points.empty()) {
    return 0;
  }

  sort(points.begin(), points.end(), [](const vector<int> &itv1, const vector<int> &itv2) {
    return itv1[1] < itv2[1];
  });

  int cnt {1};
  int end {points[0][1]};
  for (int i = 1; i < points.size(); i++) {
    if (points[i][0] > end) {
      cnt++;
      end = points[i][1];
    }
  }
  return cnt;
}

int main() {
  vector<vector<int>> points1 {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  assert(2 == findMinArrowShots(points1));

  vector<vector<int>> points2 {{-1, 1}, {0, 1}, {2, 3}, {1, 2}};
  assert(2 == findMinArrowShots(points2));

  vector<vector<int>> points3 {{-2147483648,2147483647}};
  assert(1 == findMinArrowShots(points3));

  return 0;
}