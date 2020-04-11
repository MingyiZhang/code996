//
// Created by mingyi on 11.04.20.
//

#include <vector>
#include <cassert>

std::vector<int> twoSum(const std::vector<int> &numbers, int target) {
  int i = 0, j = (int) numbers.size() - 1, sum = 0;
  std::vector<int> ret(2);
  while (i < j) {
    sum = numbers[i] + numbers[j];
    if (sum == target) {
      ret[0] = i + 1;
      ret[1] = j + 1;
      return ret;
    } else if (sum < target) {
      i++;
    } else {  // sum > target
      j--;
    }
  }
  return ret;
}

int main() {
  std::vector<int> numbers{2, 7, 9, 11};
  int target1 = 9;
  std::vector<int> result1 = twoSum(numbers, target1);
  assert(result1.size() == 2);
  assert(result1[0] == 1);
  assert(result1[1] == 2);

  int target2 = 16;
  std::vector<int> result2 = twoSum(numbers, target2);
  assert(result2.size() == 2);
  assert(result2[0] == 2);
  assert(result2[1] == 3);

  int target3 = 15;
  std::vector<int> result3 = twoSum(numbers, target3);
  assert(result3.size() == 2);
  assert(result3[0] == 0);
  assert(result3[1] == 0);

  return 0;
}
