package nonDecreasingArray;

public class Solution {
    public boolean checkPossibility(int[] nums) {
        int numberOfDecrease = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] <= nums[i + 1]) {
                continue;
            }

            if (i > 0 && nums[i - 1] > nums[i + 1]) {
                nums[i + 1] = nums[i];
            } else {
                nums[i] = nums[i + 1];
            }
            numberOfDecrease++;
            if (numberOfDecrease > 1) {
                return false;
            }
        }
        return true;
    } 
}