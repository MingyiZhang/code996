#include <vector>
#include <queue>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
  vector<vector<int>> graph(numCourses);
  vector<int> valence(numCourses, 0);
  // build graph
  for (const auto &pre : prerequisites) {
    graph[pre[0]].push_back(pre[1]);
    valence[pre[1]]++;
  }
  // get leaf node
  queue<int> q;
  for (int i = 0; i < numCourses; i++) {
    if (!valence[i]) {
      q.push(i);
    }
  }
  // remove leaf node, and their parents
  while (!q.empty()) {
    int curNode = q.front();
    q.pop();
    numCourses--;
    for (int nextNode : graph[curNode]) {
      if (--valence[nextNode] == 0) {
        q.push(nextNode);
      }
    }
  }
  return numCourses == 0;
}