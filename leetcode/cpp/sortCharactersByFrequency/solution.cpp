//
// Created by mingyi on 18.04.20.
//

#include <string>
#include <unordered_map>
#include <map>
#include <queue>
#include <cassert>
#include <sstream>
#include <iostream>

using namespace std;

string frequencySortHeap(string s) {
  // count
  unordered_map<char, int> freqMap;
  for (const auto &c : s) {
    freqMap[c]++;
  }

  // heapify
  priority_queue<pair<int, char>> freqPQ;  // (count, letter)
  for (const auto &p : freqMap) {
    freqPQ.push({p.second, p.first});
  }

  // get s
  stringstream ss;
  while (!freqPQ.empty()) {
    auto p = freqPQ.top();
    for (int i = 0; i < p.first; i++) {
      ss << p.second;
    }
    freqPQ.pop();
  }
  return ss.str();
}

string frequencySortMap(string s) {
  // count
  unordered_map<char, int> letterFreqMap;
  for (const auto &c : s) {
    letterFreqMap[c]++;
  }

  // ordered map
  map<int, vector<char>, greater<>> freqLetterMap;
  for (const auto &p : letterFreqMap) {
    freqLetterMap[p.second].push_back(p.first);
  }

  // get s
  stringstream ss;
  for (const auto &p : freqLetterMap) {
    for (const auto &c : p.second) {
      for (int i = 0; i < p.first; i++) {
        ss << c;
      }
    }
  }
  return ss.str();
}



int main() {
  assert("eetr" == frequencySortHeap("tree") || "eert" == frequencySortHeap("tree"));
  assert("cccaaa" == frequencySortHeap("cccaaa") || "aaaccc" == frequencySortHeap("cccaaa"));
  assert("bbAa" == frequencySortHeap("Aabb") || "bbaA" == frequencySortHeap("Aabb"));
  assert("eetr" == frequencySortMap("tree") || "eert" == frequencySortMap("tree"));
  assert("cccaaa" == frequencySortMap("cccaaa") || "aaaccc" == frequencySortMap("cccaaa"));
  assert("bbAa" == frequencySortMap("Aabb") || "bbaA" == frequencySortMap("Aabb"));
  return 0;
}