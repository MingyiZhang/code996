//
// Created by mingyi on 21.04.20.
//

#include <vector>
#include <cassert>

using namespace std;

char nextGreatestLetter(vector<char> &letters, char target) {
  int left = 0, right = (int) letters.size()- 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (letters[mid] <= target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return left < letters.size() ? letters[left] : letters[0];
}

int main() {
  vector<char> letters {'c', 'f', 'j'};
  assert('c' == nextGreatestLetter(letters, 'a'));
  assert('f' == nextGreatestLetter(letters, 'c'));
  assert('f' == nextGreatestLetter(letters, 'd'));
  assert('j' == nextGreatestLetter(letters, 'g'));
  assert('c' == nextGreatestLetter(letters, 'j'));
  assert('c' == nextGreatestLetter(letters, 'k'));
  return 0;
}

