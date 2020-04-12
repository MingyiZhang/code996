package sumofsquarenumbers;

public class Solution {

  /** a <= b 2 a^2 <= c = a^2 + b^2 <= 2 b^2 0 <= a <= sqrt(c / 2) sqrt(c / 2) <= b <= sqrt(c) */
  public static boolean judgeSquareSum(int c) {
    for (int a = 0; a <= (int) Math.sqrt(c / 2.); a++) {
      int b2 = c - a * a;
      int b = (int) Math.sqrt(b2);
      if (b * b == b2) {
        return true;
      }
    }
    return false;
  }

  public static void main(String[] args) {
    assert (judgeSquareSum(5));
    assert (judgeSquareSum(4));
    assert (!judgeSquareSum(3));
    assert (judgeSquareSum(2));
    assert (judgeSquareSum(16));
  }
}
