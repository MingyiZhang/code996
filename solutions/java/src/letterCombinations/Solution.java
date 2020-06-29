package letterCombinations;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Solution {
    private final Map<Character, String> numberToLettersMap = getNumberToLettersMap();

    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty()) {
            return new ArrayList<String>();
        }
        Set<String> combinations = new HashSet<>();
        getCombinations(combinations, digits, "");
        return new ArrayList<String>(combinations);
    }

    private void getCombinations(Set<String> combinations, String digits, String prefix) {
        if (prefix.length() == digits.length()) {
            combinations.add(prefix);
            return;
        }
        char digit = digits.charAt(prefix.length());
        for (char letter : numberToLettersMap.get(digit).toCharArray()) {
            getCombinations(combinations, digits, String.format("%s%c", prefix, letter));
        }
    }

    private Map<Character, String> getNumberToLettersMap() {
        Map<Character, String> numberToLettersMap = new HashMap<>();
        numberToLettersMap.put('2', "abc");
        numberToLettersMap.put('3', "def");
        numberToLettersMap.put('4', "ghi");
        numberToLettersMap.put('5', "jkl");
        numberToLettersMap.put('6', "mno");
        numberToLettersMap.put('7', "pqrs");
        numberToLettersMap.put('8', "tuv");
        numberToLettersMap.put('9', "wxyz");
        return numberToLettersMap;
    }
}