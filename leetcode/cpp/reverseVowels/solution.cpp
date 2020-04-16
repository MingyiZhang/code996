//
// Created by mingyi on 16.04.20.
//

#include <string>
#include <cassert>

using namespace std;

string reverseVowels(string s) {
  int i = 0, j = (int) s.size() - 1;
  string vows = "aeiouAEIOU";
  while (i < j) {
    if (vows.find(s[i]) != string::npos && vows.find(s[j]) != string::npos) {
      swap(s[i], s[j]);
      i++;
      j--;
    } else if (vows.find(s[i]) == string::npos) {
      i++;
    } else {  // vows.find(s[i]) == string::npos
      j--;
    }
  }
  return s;
}

int main() {
  assert(reverseVowels("leetcode") == "leotcede");
  assert(reverseVowels("") == "");
}

