import java.util.*;

class Solution {
    public int constrainedSubsetSum(int[] nums, int k) {
        Deque<Integer> q = new ArrayDeque<>();
        int[] dp = new int[nums.length];
        int max = nums[0];
        dp[0] = nums[0];

        for (int i = 1; i < nums.length; i++) {
            while (!q.isEmpty() && q.peek() < i - k) {
                q.poll();
            }

            dp[i] = Math.max(dp[q.peek()], 0) + nums[i];
            max = Math.max(max, dp[i]);

            while (!q.isEmpty() && dp[i] >= dp[q.peekLast()]) {
                q.pollLast();
            }

            q.offer(i);
        }
        return max;
    }
}

