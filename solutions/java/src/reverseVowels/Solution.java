package reverseVowels;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Solution {
    private Set<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));

    public String reverseVowels(String s) {
        int left = 0, right = s.length() - 1;
        char[] charList = s.toCharArray();
        while (left < right) {
            if (vowels.contains(charList[left]) && vowels.contains(charList[right])) {
                swap(charList, left, right);
                left++;
                right--;
            }
            while (left < right && !vowels.contains(charList[left])) {
                left++;
            }
            while (right > left && !vowels.contains(charList[right])) {
                right--;
            }
        }
        StringBuilder sBuilder = new StringBuilder();
        for (char c : charList) {
            sBuilder.append(c);
        }
        return sBuilder.toString();
    }

    private void swap(char[] array, int i, int j) {
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}