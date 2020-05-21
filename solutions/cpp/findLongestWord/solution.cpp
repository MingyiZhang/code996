//
// Created by mingyi on 16.04.20.
//

#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

string findLongestWord(string s, vector<string> &d) {
  auto isSub = [](const string &w, const string &s) {
    int found = -1;
    for (int i = 0; i < w.length(); i++) {
      char c = w[i];
      found = s.find(c, found + 1);
      if (found == string::npos || s.length() - found < w.length() - i) {
        return false;
      }
    }
    return true;
  };

  sort(d.begin(), d.end(), [](const string &s1, const string &s2) {
    return s1.size() > s2.size() || (s1.size() == s2.size() && s1 < s2);
  });
  for (const auto &c : d) {
    if (isSub(c, s)) {
      return c;
    }
  }
  return "";

// very slow version
//  string ans;
//  for (const auto &ss : d) {
//    auto it = s.begin();
//    auto itw = ss.begin();
//    while (it != s.end() && itw != ss.end()) {
//      if (*it == *itw) {
//        itw++;
//      }
//      it++;
//    }
//    if (itw == ss.end()
//        && (ss.size() > ans.size()
//            || (ss.size() == ans.size()
//                && lexicographical_compare(ss.begin(), ss.end(), ans.begin(), ans.end())))) {
//      ans = ss;
//    }
//  }
//  return ans;
}

int main() {
  string s = "abpcplea";
  vector<string> d1{"ale", "apple", "monkey", "plea"};
  string ret = findLongestWord(s, d1);
  assert("apple" == ret);

  vector<string> d2{"a", "b", "c"};
  assert("a" == findLongestWord(s, d2));

  return 0;
}
