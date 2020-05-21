package twosumii;

public class Solution {

  public static int[] twoSum(int[] numbers, int target) {
    int i = 0, j = numbers.length - 1, sum = 0;
    int[] ret = {0, 0};
    while (i < j) {
      sum = numbers[i] + numbers[j];
      if (sum == target) {
        ret[0] = i + 1;
        ret[1] = j + 1;
        return ret;
      } else if (sum < target) {
        i++;
      } else { // sum > target
        j--;
      }
    }
    return ret;
  }

  public static void main(String[] args) {
    int[] numbers = {2, 7, 9, 11};
    int target1 = 9;
    int[] result1 = twoSum(numbers, target1);
    assert(result1[0] == 1);
    assert (result1[1] == 2);
  }
}
