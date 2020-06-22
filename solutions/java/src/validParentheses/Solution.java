package validParentheses;

import java.util.Stack;

public class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '{' || c == '[' || c == '(') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }
                char cOut = stack.pop();
                boolean b1 = c == ')' && cOut != '(';
                boolean b2 = c == ']' && cOut != '[';
                boolean b3 = c == '}' && cOut != '{';
                if (b1 || b2 || b3) {
                    return false;
                }

            }
        }
        return stack.isEmpty();
    }
}