package sortCharactersByFrequency;

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> charToCount = countFrequency(s);

        PriorityQueue<Map.Entry<Character, Integer>> maxFrequencyHeap = new PriorityQueue<>(
                (e1, e2) -> e2.getValue() - e1.getValue());
        maxFrequencyHeap.addAll(charToCount.entrySet());

        StringBuilder stringBuilder = new StringBuilder();
        while (!maxFrequencyHeap.isEmpty()) {
            Map.Entry<Character, Integer> charToFreq = maxFrequencyHeap.poll();
            for (int i = 0; i < charToFreq.getValue(); i++) {
                stringBuilder.append(charToFreq.getKey());
            }
        }
        return stringBuilder.toString();

    }

    private Map<Character, Integer> countFrequency(String s) {
        Map<Character, Integer> charToCount = new HashMap<>();
        for (char c : s.toCharArray()) {
            charToCount.put(c, charToCount.getOrDefault(c, 0) + 1);
        }
        return charToCount;
    }
}