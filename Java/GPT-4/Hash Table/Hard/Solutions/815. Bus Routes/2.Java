import java.util.*;

class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) return 0;

        // Building graph
        Map<Integer, List<Integer>> stopToBuses = new HashMap<>();
        for (int i = 0; i < routes.length; i++) {
            for (int stop : routes[i]) {
                stopToBuses.computeIfAbsent(stop, x -> new ArrayList<>()).add(i);
            }
        }

        Queue<Integer> queue = new LinkedList<>();
        queue.offer(source);
        boolean[] visited = new boolean[routes.length];
        int buses = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            buses++;
            for (int i = 0; i < size; i++) {
                int stop = queue.poll();
                for (int bus : stopToBuses.get(stop)) {
                    if (visited[bus]) continue;
                    visited[bus] = true;
                    for (int nextStop : routes[bus]) {
                        if (nextStop == target) return buses;
                        queue.offer(nextStop);
                    }
                }
            }
        }

        return -1;
    }
}
