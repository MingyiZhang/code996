#include <vector>

using namespace std;

bool isBipartite(int curNode, int curColor, vector<int> &colors, vector<vector<int>> &graph) {
  if (colors[curNode] != -1) {
    return colors[curNode] == curColor;
  }
  colors[curNode] = curColor;
  for (int nextNode : graph[curNode]) {
    if (!isBipartite(nextNode, 1 - curColor, colors, graph)) {
      return false;
    }
  }
  return true;
}

bool isBipartite(vector<vector<int>> &graph) {
  vector<int> colors(graph.size(), -1);
  for (int i = 0; i < graph.size(); i++) {
    if (colors[i] == -1 && !isBipartite(i, 0, colors, graph)) {
      return false;
    }
  }
  return true;
}