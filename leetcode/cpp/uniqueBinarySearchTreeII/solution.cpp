//
// Created by mingyi on 22.04.20.
//

#include <vector>
#include <map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// divide conquer recursion method
vector<TreeNode*> divideConquer(int left, int right) {
  if (left > right) {
    return vector<TreeNode*>{nullptr};
  }

  vector<TreeNode*> trees;
  for (int i = left; i <= right; i++) {
    vector<TreeNode*> leftTrees = divideConquer(left, i - 1);
    vector<TreeNode*> rightTrees = divideConquer(i + 1, right);
    for (auto leftTree : leftTrees) {
      for (auto rightTree : rightTrees) {
        auto head = new TreeNode(i);
        head->left = leftTree;
        head->right = rightTree;
        trees.push_back(head);
      }
    }
  }
  return trees;
}

vector<TreeNode*> generateTreesDivideConquer(int n) {
  if (n == 0) {
    return vector<TreeNode*>{};
  }
  return divideConquer(1, n);
}


// dynamic programming
vector<TreeNode*> dynamicProgramming(int left, int right, map<pair<int, int>, vector<TreeNode*>> &mp) {
  if (left > right) {
    return vector<TreeNode*>{nullptr};
  }
  pair<int, int> key {left, right};
  if (mp.find(key) != mp.end()) {
    return mp[key];
  }

  vector<TreeNode*> trees;
  for (int i = left; i <= right; i++) {
    vector<TreeNode*> leftTrees = dynamicProgramming(left, i - 1, mp);
    vector<TreeNode*> rightTrees = dynamicProgramming(i + 1, right, mp);
    for (TreeNode *tree1 : leftTrees) {
      for (TreeNode *tree2 : rightTrees) {
        auto head = new TreeNode(i);
        head->left = tree1;
        head->right = tree2;
        trees.push_back(head);
      }
    }
  }
  mp[key] = trees;
  return trees;
}

vector<TreeNode*> generateTreesDynamicProgramming(int n) {
  if (n == 0) {
    return vector<TreeNode*>{};
  }
  map<pair<int, int>, vector<TreeNode*>> mp;
  return dynamicProgramming(1, n, mp);
}
