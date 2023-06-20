class Solution {
    public boolean find132pattern(int[] nums) {
        int n = nums.length;
        int[] max = new int[n];
        max[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            max[i] = Math.max(max[i + 1], nums[i]);
        }

        Stack<Integer> stack = new Stack<>();
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < max[i]) {
                while (!stack.isEmpty() && stack.peek() <= nums[i]) {
                    stack.pop();
                }
                if (!stack.isEmpty() && stack.peek() < max[i]) {
                    return true;
                }
                stack.push(nums[i]);
            }
        }
        return false;
    }
}
