package bestTimeToBuyAndSellStock;

public class Solution {
    public int maxProfit(int[] prices) {
        int ret = 0;
        int lowest = 1000000;
        for (int p : prices) {
            if (p > lowest) {
                ret = Math.max(ret, p - lowest);
            } else {
                lowest = p;
            }
        }
        return ret;
    }
}