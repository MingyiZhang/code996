//
// Created by mingyi on 20.04.20.
//

#include <vector>
#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;

vector<int> partitionLabels(string S) {
//  // first solution slow
//  unordered_map<char, int> ends;
//  for (int i = 0; i < S.size(); i++) {
//    ends[S[i]] = i;
//  }
//
//  vector<int> ans;
//  int start = 0;
//  int prev = 0;
//  while (start < S.size()) {
//    int end = ends[S[start]];
//    while (start++ < end) {
//      end = max(end, ends[S[start]]);
//    }
//    ans.push_back(start - prev);
//    prev = start;
//  }
//  return ans;

//  // second solution
//  vector<int> ends(26, -1);
//  for (int i = 0; i < S.size(); i++) {
//    ends[S[i] - 'a'] = i;
//  }
//
//  vector<int> ans;
//  int start = 0;
//  int prev = 0;
//  while (start < S.size()) {
//    int end = ends[S[start] - 'a'];
//    while (start++ < end) {
//      end = max(end, ends[S[start] - 'a']);
//    }
//    ans.push_back(start - prev);
//    prev = start;
//  }
//  return ans;

  // third solution
  vector<int> ends(26, -1);
  for (int i = 0; i < S.length(); i++) {
    ends[S[i] - 'a'] = i;
  }

  vector<int> ans;
  int begin = 0, end = 0;
  for (int i = 0; i < S.length(); i++) {
    if (ends[S[i] - 'a'] > end) {
      end = ends[S[i] - 'a'];
    }
    if (i == end) {
      ans.push_back(end - begin + 1);
      begin = i + 1;
    }
  }
  return ans;
}

int main() {
  string S = "ababcbacadefegdehijhklij";
  vector<int> expect {9, 7, 8};
  vector<int> result = partitionLabels(S);
  for (int i = 0; i < result.size(); i++) {
    assert(expect[i] == result[i]);
  }
}