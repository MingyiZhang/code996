//
// Created by mingyi on 20.04.20.
//

#include <string>
#include <cassert>

using namespace std;

bool isSubsequence(string s, string t) {
  int idx = -1;
  for (char c: s) {
    idx = t.find(c, idx + 1);
    if (idx == -1) {
      return false;
    }
  }
  return true;

//  int i = 0, j = 0;
//  while (i < s.size() and j < t.size()) {
//    if (s[i] == t[j++]) {
//      i++;
//    }
//  }
//  return i == s.size();
}

int main() {
  assert(isSubsequence("abc", "ahbgdc"));
  assert(!isSubsequence("axc", "ahbgdc"));
  return 0;
}
