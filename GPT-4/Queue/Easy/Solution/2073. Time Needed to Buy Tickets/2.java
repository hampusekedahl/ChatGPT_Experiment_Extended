import java.util.*;

class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int n = tickets.length;
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            queue.offer(new int[] {tickets[i], i});
        }
        int time = 0;
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            time++;
            if (current[0] > 1) {
                current[0]--;
                queue.offer(current);
            }
            if (current[1] == k && current[0] == 1) {
                break;
            }
        }
        return time;
    }
}

