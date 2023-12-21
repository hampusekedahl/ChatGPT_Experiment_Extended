class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int sumOfNNumbers = n * (n + 1) / 2;
        int sumOfNums = 0;
        
        for (int num : nums) {
            sumOfNums += num;
        }
        
        return sumOfNNumbers - sumOfNums;
    }
}
