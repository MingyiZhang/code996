package queueReconstructionByHeight;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (p1, p2) -> {
            if (p1[0] == p2[0]) {
                return p1[1] - p2[1];
            }
            return p2[0] - p1[0];
        });
        List<int[]> array = new ArrayList<>();
        for (int i = 0; i < people.length; i++) {
            array.add(people[i][1], people[i]);       
        }
        int[][] ret = new int[people.length][2];
        for (int i = 0; i < people.length; i++) {
            ret[i] = array.get(i);
        }
        return ret;
    }
}