import java.util.Arrays;

class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        
        int low = 0;
        int high = nums[nums.length - 1] - nums[0];
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (countPairsWithDistanceLessThan(nums, mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
    
    private int countPairsWithDistanceLessThan(int[] nums, int target) {
        int count = 0;
        int left = 0;
        
        for (int right = 0; right < nums.length; right++) {
            while (nums[right] - nums[left] > target) {
                left++;
            }
            
            count += right - left;
        }
        
        return count;
    }
}

