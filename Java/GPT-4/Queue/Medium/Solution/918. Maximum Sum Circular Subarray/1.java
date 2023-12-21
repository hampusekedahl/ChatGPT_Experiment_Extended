class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int total = 0, maxSum = Integer.MIN_VALUE, curMax = 0;
        int minSum = Integer.MAX_VALUE, curMin = 0;

        for (int num : nums) {
            curMax = Math.max(curMax + num, num);
            maxSum = Math.max(maxSum, curMax);
            curMin = Math.min(curMin + num, num);
            minSum = Math.min(minSum, curMin);
            total += num;
        }
        
        return maxSum > 0 ? Math.max(maxSum, total - minSum) : maxSum;
    }
}

