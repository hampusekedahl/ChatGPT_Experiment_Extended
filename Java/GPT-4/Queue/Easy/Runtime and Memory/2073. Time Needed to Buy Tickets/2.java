import java.util.*;

class Solution {
    class Pair {
        int idx, tickets;
        public Pair(int idx, int tickets) {
            this.idx = idx;
            this.tickets = tickets;
        }
    }

    public int timeRequiredToBuy(int[] tickets, int k) {
        Deque<Pair> queue = new LinkedList<>();
        
        for (int i = 0; i < tickets.length; i++) {
            queue.offer(new Pair(i, tickets[i]));
        }
        
        int time = 0;
        while (!queue.isEmpty()) {
            Pair current = queue.poll();
            current.tickets--;
            time++;
            
            if (current.idx == k && current.tickets == 0) {
                return time;
            }
            
            if (current.tickets > 0) {
                queue.offer(current);
            }
        }
        return -1; // Shouldn't reach here as we are guaranteed to be able to sell all tickets
    }
}

