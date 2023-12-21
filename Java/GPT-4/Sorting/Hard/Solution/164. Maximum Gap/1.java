class Solution {
    public int maximumGap(int[] nums) {
        if (nums == null || nums.length < 2) {
            return 0;
        }
        
        // get the max and min value of the array
        int min = nums[0];
        int max = nums[0];
        for (int i : nums) {
            min = Math.min(min, i);
            max = Math.max(max, i);
        }
        
        // calculate the minimum possible maximum difference, ceiling of the integer division
        int gap = (int) Math.ceil((double) (max - min) / (nums.length - 1));
        
        int[] bucketsMin = new int[nums.length - 1];
        int[] bucketsMax = new int[nums.length - 1];
        Arrays.fill(bucketsMin, Integer.MAX_VALUE);
        Arrays.fill(bucketsMax, Integer.MIN_VALUE);
        
        // put numbers into buckets
        for (int i : nums) {
            if (i == min || i == max) {
                continue;
            }
            int idx = (i - min) / gap; // index of the right bucket
            bucketsMin[idx] = Math.min(i, bucketsMin[idx]);
            bucketsMax[idx] = Math.max(i, bucketsMax[idx]);
        }
        
        // scan the buckets for the max gap
        int maxGap = Integer.MIN_VALUE;
        int previous = min;
        for (int i = 0; i < nums.length - 1; i++) {
            if (bucketsMin[i] == Integer.MAX_VALUE && bucketsMax[i] == Integer.MIN_VALUE) {
                // empty bucket
                continue;
            }
            // max gap is the difference between the current bucket's min and the previous bucket's max 
            maxGap = Math.max(maxGap, bucketsMin[i] - previous); 
            previous = bucketsMax[i];
        }
        maxGap = Math.max(maxGap, max - previous); // update the final max value gap
        
        return maxGap;
    }
}

