package queueReconstructionByHeight;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (p1, p2) -> p1[0] == p2[0] ? p1[1] - p2[1] : p2[0] - p1[0]);
        
        List<int[]> sortedList = new ArrayList<>();
        for (int[] p : people) {
            sortedList.add(p[1], p);
        }
        return sortedList.toArray(new int[people.length][]);
    }
}