package partitionLabels;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<Integer> partitionLabels(String S) {
        int[] ends = new int[26];
        for (int i = 0; i < S.length(); i++) {
            ends[S.charAt(i) - 'a'] = i;
        }
        int start = 0, end = 0;
        List<Integer> ret = new ArrayList<>();
        for (int i = 0; i < S.length(); i++) {
            if (ends[S.charAt(i) - 'a'] > end) {
                end = ends[S.charAt(i) - 'a'];
            } 
            if (end == i) {
                ret.add(end - start + 1);
                start = i + 1;
            } 
        }
        return ret;
    }
}