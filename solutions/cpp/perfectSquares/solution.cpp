//
// Created by mingyi on 24.04.20.
//

#include <vector>
#include <queue>
#include <cassert>

using namespace std;

vector<int> squares(int n) {
  int current = 1;
  int diff = 3;
  vector<int> sq;
  while (current <= n) {
    sq.push_back(current);
    current += diff;
    diff += 2;
  }
  return sq;
}

int numSquaresBFS(int n) {
  vector<int> sq = squares(n);
  vector<bool> visited(n + 1, false);
  queue<int> q;
  q.push(n);
  visited[n] = true;
  int count = 0;
  while (!q.empty()) {
    count++;
    int qSize = q.size();
    while (qSize--) {
      int cur = q.front();
      q.pop();
      for (int s : sq) {
        int next = cur - s;
        if (next < 0) {
          break;
        }
        if (next == 0) {
          return count;
        }
        if (visited[next]) {
          continue;
        }
        visited[next] = true;
        q.push(next);
      }
    }
  }
  return count;
}

int main() {
  vector<int> expectSquares{1, 4, 9, 16};
  vector<int> resultSquares = squares(20);
  for (int i = 0; i < resultSquares.size(); i++) {
    assert(expectSquares[i] == resultSquares[i]);
  }
  assert(3 == numSquaresBFS(12));
  assert(2 == numSquaresBFS(13));
  return 0;
}