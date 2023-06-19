import java.util.*;

class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) return 0;
        int n = routes.length;
        boolean[][] edge = new boolean[n][n];
        Map<Integer, List<Integer>> mapToRoute = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < routes[i].length; j++) {
                List<Integer> buses = mapToRoute.getOrDefault(routes[i][j], new ArrayList<>());
                for (int bus: buses) {
                    edge[i][bus] = edge[bus][i] = true;
                }
                buses.add(i);
                mapToRoute.put(routes[i][j], buses);
            }
        }
        Queue<Integer> queue = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();
        for (int bus: mapToRoute.getOrDefault(source, new ArrayList<>())) {
            visited.add(bus);
            queue.offer(bus);
        }
        int buses = 1;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int currentBus = queue.poll();
                for (int nextBus = 0; nextBus < n; nextBus++) {
                    if (edge[currentBus][nextBus] && visited.add(nextBus)) {
                        for (int stop: routes[nextBus]) {
                            if (stop == target) return buses;
                            queue.offer(nextBus);
                        }
                    }
                }
            }
            buses++;
        }
        return -1;
    }
}
