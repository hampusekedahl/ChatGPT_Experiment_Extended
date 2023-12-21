class Solution {
    public int maximumGap(int[] nums) {
        if (nums.length < 2) return 0;
        int min = nums[0], max = nums[0], n = nums.length;
        for (int num : nums) {
            min = Math.min(min, num);
            max = Math.max(max, num);
        }
        int gap = (int) Math.ceil((double) (max - min) / (n - 1));
        int[] bucketsMin = new int[n - 1];
        int[] bucketsMax = new int[n - 1];
        Arrays.fill(bucketsMin, Integer.MAX_VALUE);
        Arrays.fill(bucketsMax, Integer.MIN_VALUE);
        for (int num : nums) {
            if (num == min || num == max) continue;
            int idx = (num - min) / gap;
            bucketsMin[idx] = Math.min(num, bucketsMin[idx]);
            bucketsMax[idx] = Math.max(num, bucketsMax[idx]);
        }
        int maxGap = Integer.MIN_VALUE;
        int previousMax = min;
        for (int i = 0; i < n - 1; i++) {
            if (bucketsMin[i] == Integer.MAX_VALUE && bucketsMax[i] == Integer.MIN_VALUE)
                // empty bucket
                continue;
            // non-empty bucket
            maxGap = Math.max(maxGap, bucketsMin[i] - previousMax);
            previousMax = bucketsMax[i];
        }
        maxGap = Math.max(maxGap, max - previousMax); // update the final max value gap
        return maxGap;
    }
}
