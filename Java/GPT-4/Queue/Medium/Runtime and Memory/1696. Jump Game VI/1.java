
import java.util.*;

class Solution {
    public int maxResult(int[] nums, int k) {
        int n = nums.length;
        Deque<Integer> deque = new LinkedList<>();
        int[] dp = new int[n];
        dp[0] = nums[0];
        deque.offer(0);

        for (int i = 1; i < n; i++) {
            // i - k > deque.peek() means the index is out of the window
            if (i - k > deque.peek()) {
                deque.poll();
            }
            dp[i] = nums[i] + dp[deque.peek()];
            
            // keep deque in descending order
            while (!deque.isEmpty() && dp[i] > dp[deque.peekLast()]) {
                deque.pollLast();
            }
            deque.offer(i);
        }

        return dp[n - 1];
    }
}
