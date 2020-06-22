package dailyTemperatures;

import java.util.Stack;

public class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] ret = new int[T.length];
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < T.length; i++) {
            while (!stack.isEmpty() && T[i] > T[stack.peek()]) {
                int k = stack.peek();
                ret[k] = i - k;
                stack.pop();
            }
            stack.push(i);
        }
        return ret;
    }
}