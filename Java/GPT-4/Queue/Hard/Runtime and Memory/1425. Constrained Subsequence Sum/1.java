import java.util.*;

class Solution {
    public int constrainedSubsetSum(int[] nums, int k) {
        int n = nums.length;
        int[] dp = new int[n];
        Deque<Integer> q = new LinkedList<>();
        
        int max = Integer.MIN_VALUE;
        
        for (int i = 0; i < n; i++) {
            if (!q.isEmpty() && q.peekFirst() < i - k) {
                q.pollFirst();
            }
            dp[i] = Math.max(nums[i], nums[i] + (q.isEmpty() ? 0 : dp[q.peekFirst()]));
            while (!q.isEmpty() && dp[i] > dp[q.peekLast()]) {
                q.pollLast();
            }
            q.offerLast(i);
            max = Math.max(max, dp[i]);
        }
        return max;
    }
}

