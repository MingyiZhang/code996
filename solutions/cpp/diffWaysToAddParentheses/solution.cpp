//
// Created by mingyi on 22.04.20.
//

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int operatorHelper(int x, int y, char op) {
  switch (op) {
    case '+':
      return x + y;
    case '-':
      return x - y;
    case '*':
      return x * y;
    default:
      throw;
  }
}

// Divide and conquer solution, which is slow due to duplicated computing while recursion
vector<int> divideConquer(const string &input, int left, int right) {
  vector<int> ret;
  for (int i = left; i <= right; i++) {
    if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
      vector<int> leftRet = divideConquer(input, left, i - 1);
      vector<int> rightRet = divideConquer(input, i + 1, right);
      for (int x : leftRet) {
        for (int y : rightRet) {
          ret.push_back(operatorHelper(x, y, input[i]));
        }
      }
    }
  }
  if (ret.empty()) {
    ret.push_back(stoi(input.substr(left, right - left + 1)));
  }
  return ret;
}

vector<int> diffWaysToComputeDivideConquer(const string &input) {
  return divideConquer(input, 0, (int) input.size() - 1);
}

// Dynamic programming solution, which is faster
vector<int> dynamicProgramming(const string &input, unordered_map<string, vector<int>> &mp) {
  if (mp.find(input) != mp.end()) {
    return mp[input];
  }

  vector<int> ret;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
      string substr1 = input.substr(0, i);
      vector<int> ret1;
      if (mp.find(substr1) != mp.end()) {
        ret1 = mp[substr1];
      } else {
        ret1 = dynamicProgramming(substr1, mp);
        mp[substr1] = ret1;
      }
      string substr2 = input.substr(i + 1, input.size() - i - 1);
      vector<int> ret2;
      if (mp.find(substr2) != mp.end()) {
        ret2 = mp[substr2];
      } else {
        ret2 = dynamicProgramming(substr2, mp);
        mp[substr2] = ret2;
      }
      for (int x : ret1) {
        for (int y : ret2) {
          ret.push_back(operatorHelper(x, y, input[i]));
        }
      }
    }
  }
  if (ret.empty()) {
    ret.push_back(stoi(input));
  }

  mp[input] = ret;
  return ret;
}

vector<int> diffWaysToComputeDynamicProgramming(const string &input) {
  unordered_map<string, vector<int>> mp;
  return dynamicProgramming(input, mp);
}

int main() {
  string input1 = "2-1-1";
  vector<int> result1 = diffWaysToComputeDivideConquer(input1);
  for (int x : result1) {
    cout << x << ' ';
  }
  cout << '\n';
  for (int x : diffWaysToComputeDynamicProgramming(input1)) {
    cout << x << ' ';
  }
  return 0;
}