
import java.util.*;

class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        PriorityQueue<int[]> queue = new PriorityQueue<>(
            (a, b) -> a[1] == b[1] ? a[0] - b[0] : b[1] - a[1]
        );

        for (int i = 0; i < tickets.length; i++) {
            queue.add(new int[] {i, tickets[i]});
        }

        int time = 0;
        while (!queue.isEmpty()) {
            int[] person = queue.poll();
            time++;
            
            if (person[0] == k && person[1] == 1) {
                return time;
            }

            if (person[1] > 1) {
                queue.add(new int[] {person[0], person[1] - 1});
            }
        }

        return -1; // This should not be reachable as the person at position k should have left the queue
    }
}
