import java.util.*;

class Solution {
    public int racecar(int target) {
        Deque<int[]> queue = new ArrayDeque<>();
        Set<String> visited = new HashSet<>();
        queue.offer(new int[]{0, 1}); //position, speed
        visited.add("0_1");
        int level = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] curr = queue.poll();
                int pos = curr[0];
                int speed = curr[1];
                if (pos == target) {
                    return level;
                }
                int[] next = new int[]{pos + speed, speed * 2};
                String nextStr = next[0] + "_" + next[1];
                if (!visited.contains(nextStr) && Math.abs(next[0]) <= target * 2) {
                    queue.offer(next);
                    visited.add(nextStr);
                }
                next = new int[]{pos, speed > 0 ? -1 : 1};
                nextStr = next[0] + "_" + next[1];
                if (!visited.contains(nextStr) && Math.abs(next[0]) <= target * 2) {
                    queue.offer(next);
                    visited.add(nextStr);
                }
            }
            level++;
        }
        return -1;
    }
}
