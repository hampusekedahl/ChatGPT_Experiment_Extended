class Solution {
    public void sortColors(int[] nums) {
        int p0 = 0, curr = 0;
        int p2 = nums.length - 1;
        
        int temp;
        while (curr <= p2) {
            if (nums[curr] == 0) {
                // swap nums[curr] and nums[p0]
                temp = nums[p0];
                nums[p0++] = nums[curr];
                nums[curr++] = temp;
            } else if (nums[curr] == 2) {
                // swap nums[curr] and nums[p2]
                temp = nums[curr];
                nums[curr] = nums[p2];
                nums[p2--] = temp;
            } else {
                curr++;
            }
        }
    }
}
