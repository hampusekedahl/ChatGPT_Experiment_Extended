import java.util.Deque;
import java.util.LinkedList;

public class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        int[] prefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        Deque<Integer> deque = new LinkedList<>();
        int minLen = n + 1;
        for (int y = 0; y < prefixSum.length; y++) {
            while (!deque.isEmpty() && prefixSum[y] <= prefixSum[deque.getLast()]) {
                deque.removeLast();
            }
            while (!deque.isEmpty() && prefixSum[y] >= prefixSum[deque.getFirst()] + k) {
                minLen = Math.min(minLen, y - deque.removeFirst());
            }
            deque.addLast(y);
        }
        return minLen < n + 1 ? minLen : -1;
    }
}

