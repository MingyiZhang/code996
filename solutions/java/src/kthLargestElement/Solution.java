package kthLargestElement;

public class Solution {
    public int findKthLargest(int[] nums, int k) {
        return findKthLargestImpl(nums, 0, nums.length - 1, k);
    }

    private int findKthLargestImpl(int[] nums, int left, int right, int k) {
        int pIndex = getPartition(nums, left, right);
        int kIndex = k - 1;
        if (pIndex == kIndex) {
            return nums[pIndex];
        } else if (pIndex < kIndex) {
            return findKthLargestImpl(nums, pIndex + 1, right, k);
        } else {
            return findKthLargestImpl(nums, left, pIndex - 1, k);
        }
    }

    private int getPartition(int[] nums, int left, int right) {
        // [left+1...j-1] > v, [j...i-1] <= v
        int v = nums[left];
        int j = left + 1, i = left + 1;
        while (i <= right) {
            if (nums[i] > v) {
                swap(nums, i, j);
                j++;
            }
            i++;
        }
        swap(nums, left, j - 1);
        return j - 1;
       
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}