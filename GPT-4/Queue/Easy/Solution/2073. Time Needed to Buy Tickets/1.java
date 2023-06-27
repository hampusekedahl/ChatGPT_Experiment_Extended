
import java.util.*;

class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        PriorityQueue<int[]> queue = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0];
            } else {
                return a[1] - b[1];
            }
        });
        
        for (int i = 0; i < tickets.length; i++) {
            queue.offer(new int[]{tickets[i], i});
        }
        
        int time = 0;
        while (true) {
            int[] top = queue.poll();
            time++;
            
            if (top[1] == k && top[0] == 1) {
                break;
            } else if (top[0] > 1) {
                queue.offer(new int[]{top[0] - 1, top[1]});
            }
        }
        return time;
    }
}
