
import java.util.*;

class Solution {
    public int findMaxValueOfEquation(int[][] points, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        int res = Integer.MIN_VALUE;
        
        for (int[] point : points) {
            while (!pq.isEmpty() && point[0] - pq.peek()[0] > k) {
                pq.poll();
            }
            
            if (!pq.isEmpty()) {
                res = Math.max(res, pq.peek()[1] + point[0] + point[1]);
            }
            
            pq.offer(new int[]{point[0], point[1] - point[0]});
        }
        
        return res;
    }
}
