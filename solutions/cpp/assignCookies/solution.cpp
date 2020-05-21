//
// Created by mingyi on 18.04.20.
//

#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s) {
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());
  int i = g.size() - 1;
  int j = s.size() - 1;
  int count = 0;
  while (i >= 0 && j >= 0) {
    if (g[i--] <= s[j]) {
      j--;
      count++;
    }
  }
  return count;
}

int main() {
  vector<int> g1 {1, 2, 3};
  vector<int> s1 {1, 1};
  assert(1 == findContentChildren(g1, s1));

  vector<int> g2 {1, 2};
  vector<int> s2 {1, 2, 3};
  assert(2 == findContentChildren(g2, s2));
  return 0;
}