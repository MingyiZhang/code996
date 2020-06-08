package diffWaysToAddParentheses;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        Map<String, List<Integer>> m = new HashMap<>();
        return dynamicProgramming(input, m);
    }

    private List<Integer> dynamicProgramming(String input, Map<String, List<Integer>> m) {
        if (m.containsKey(input)) {
            return m.get(input);
        }
        List<Integer> ret = new ArrayList<>();
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == '+' || input.charAt(i) == '-' || input.charAt(i) == '*') {
                char op = input.charAt(i);
                List<Integer> left = dynamicProgramming(input.substring(0, i), m);
                List<Integer> right = dynamicProgramming(input.substring(i + 1), m);
                for (Integer x : left) {
                    for (Integer y : right) {
                        ret.add(operatorHelper(x, y, op));
                    }
                }
                
            }
        }
        if (ret.isEmpty()) {
            ret.add(Integer.parseInt(input));
        }
        m.put(input, ret);
        return ret;
    }

    private Integer operatorHelper(Integer x, Integer y, char op) {
        switch (op) {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            default:
                return 0;
        }
    }
}