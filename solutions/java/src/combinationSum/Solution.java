package combinationSum;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> combinations = new ArrayList<>();
        List<Integer> prefix = new ArrayList<>();
        backtracking(combinations, prefix, 0, 0, candidates, target);
        return combinations;
    }

    private void backtracking(List<List<Integer>> combinations, List<Integer> prefix, int preSum, int index, int[] candidate, int target) {
        if (preSum == target && !prefix.isEmpty()) {
            combinations.add(new ArrayList<>(prefix));
            return;
        }

        for (int i = index; i < candidate.length; i++) {
            if (preSum + candidate[i] <= target) {
                prefix.add(candidate[i]);
                backtracking(combinations, prefix, preSum + candidate[i], i, candidate, target);
                prefix.remove(prefix.size() - 1);
            } else {
                break;
            }
        }
    }
}