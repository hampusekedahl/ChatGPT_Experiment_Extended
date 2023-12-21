import java.util.Arrays;

class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int count = 0;
        for (int i = nums.length - 1; i >= 2; i--) {
            int start = 0, end = i - 1;
            while (start < end) {
                // If the sum of the two shorter sides > the longest side, it forms a valid triangle
                if (nums[start] + nums[end] > nums[i]) {
                    // The two shorter sides can form valid triangles with any side that is shorter than nums[i]
                    count += end - start;
                    end--;
                } else {
                    start++;
                }
            }
        }
        return count;
    }
}

