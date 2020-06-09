package sumOfSquareNumbers;

public class solution {
    public boolean judgeSquareSum(int c) {
        int i = 0, j = (int) Math.sqrt(c);
        while (i <= j) {
            int s = i * i + j * j;
            if (s == c) {
                return true;
            } else if (s < c) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }

}