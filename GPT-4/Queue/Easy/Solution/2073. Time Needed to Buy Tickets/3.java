import java.util.*;

class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int n = tickets.length;
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            queue.offer(new int[] {tickets[i], i});
        }
        int time = 0;
        while (true) {
            int[] current = queue.poll();
            current[0]--;
            time++;
            if (current[1] == k && current[0] == 0) {
                break;
            }
            if (current[0] > 0) {
                queue.offer(current);
            }
        }
        return time;
    }
}
