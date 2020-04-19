//
// Created by mingyi on 19.04.20.
//

#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

// insert lowest first, fast
vector<vector<int>> reconstructQueueLowestFirst(vector<vector<int>> &people) {
  sort(people.begin(), people.end(), [](const auto &p1, const auto &p2) {
    if (p1[0] == p2[0]) {
      return p1[1] > p2[1];
    } else {
      return p1[0] < p2[0];
    }
//    return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] > p2[1]);  // this one line return is slower than the above one
  });

  int size = people.size();
  vector<int> pos;
  for (int i = 0; i < size; i++) {
    pos.push_back(i);
  }

  vector<vector<int>> ret(size);
  for (int i = 0; i < size; i++) {
    int k = people[i][1];
    ret[pos[k]] = people[i];
    pos.erase(pos.begin() + k);
  }
  return ret;
}

// insert highest first, slow
vector<vector<int>> reconstructQueueHighestFirst(vector<vector<int>> &people) {
  sort(people.begin(), people.end(), [](const auto &p1, const auto &p2) {
    return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
  });

  vector<vector<int>> ans;
  for (const auto &p : people) {
    ans.insert(ans.cbegin() + p[1], p);  // this is slow, every insertion is O(n) for copy
  }
  return ans;
}

int main() {
  vector<vector<int>> people {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  vector<vector<int>> expect {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};
//  vector<vector<int>> result = reconstructQueueHighestFirst(people);
  vector<vector<int>> result = reconstructQueueLowestFirst(people);
  for (int i = 0; i < result.size(); i++) {
    assert(expect[i][0] == result[i][0]);
    assert(expect[i][1] == result[i][1]);
  }
  return 0;
}