package sortColors;

public class solution {
    public void sortColors(int[] nums) {
        // [0...j-1] == 0, [j...i-1] == 1, [i] = v, [k...n-1] == 2
        int n = nums.length;
        int i = 0, j = 0, k = n;
        while (i < k) {
            int v = nums[i];
            if (v == 1) {
                i++;
            } else if (v == 0) {
                swap(i, j, nums);
                i++;
                j++;
            } else {  // v == 2
                swap(i, k - 1, nums);
                k--;
            }
        }
    }

    private void swap(int i, int j, int[] nums) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}