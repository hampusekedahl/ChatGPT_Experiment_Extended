
import java.util.*;

class Solution {
    public int findMaxValueOfEquation(int[][] points, int k) {
        // use a priority queue to store pairs with larger y - x values and smaller x values
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]  // sort based on y - x and then x
        );
        
        int res = Integer.MIN_VALUE;
        for (int[] point : points) {
            while (!pq.isEmpty() && point[0] - pq.peek()[1] > k) {
                pq.poll(); // remove if x difference is larger than k
            }
            
            if (!pq.isEmpty()) {
                res = Math.max(res, point[0] + point[1] + pq.peek()[0]); // update result
            }
            
            pq.offer(new int[] {point[1] - point[0], point[0]}); // add current pair to the queue
        }
        
        return res;
    }
}
