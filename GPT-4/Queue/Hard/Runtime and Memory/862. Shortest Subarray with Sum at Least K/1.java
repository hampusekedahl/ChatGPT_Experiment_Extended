import java.util.*;

class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        long[] sum = new long[n+1];
        for(int i = 0; i < n; i++) sum[i+1] = sum[i] + nums[i];
        
        int ans = n+1;
        Deque<Integer> dq = new LinkedList<>();
        for(int i = 0; i < n+1; i++){
            while(!dq.isEmpty() && sum[i] - sum[dq.getFirst()] >= k)
                ans = Math.min(ans, i - dq.removeFirst());
            while(!dq.isEmpty() && sum[i] <= sum[dq.getLast()])
                dq.removeLast();
            dq.addLast(i);
        }
        return ans <= n ? ans : -1;
    }
}

