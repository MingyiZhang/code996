package integerBreak;

public class Solution {
    public int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int p = n / 3;
        int r = n % 3;
        int ret = 1;
        for (int i = 1; i < p; i++) {
            ret *= 3;
        }
        if (r == 0) {
            return ret * 3;
        } else if (r == 1) {
            return ret * 4;
        } else {
            return ret * 3 * r;
        }
    }
}