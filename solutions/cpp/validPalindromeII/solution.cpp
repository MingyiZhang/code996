//
// Created by mingyi on 16.04.20.
//

#include <string>
#include <cassert>

using namespace std;

bool isPalindrome(string &s, int l, int r) {
  while (l < r) {
    if (s[l++] != s[r--]) {
      return false;
    }
  }
  return true;
}

bool validPalindromeII(string s) {
  int i = 0, j = (int) s.size() - 1;
  while (i < j) {
    if (s[i] != s[j]) {
      return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
    }
    i++;
    j--;
  }
  return true;
}

int main() {
  assert(validPalindromeII("abcba"));
  assert(validPalindromeII("abcbba"));
  assert(!validPalindromeII("abcbbda"));
}

