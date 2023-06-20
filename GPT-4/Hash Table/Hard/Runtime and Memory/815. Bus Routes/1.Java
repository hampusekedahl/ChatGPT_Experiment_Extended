import java.util.*;

class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        int n = routes.length;
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            Arrays.sort(routes[i]);
            graph.add(new ArrayList<>());
        }

        // build graph
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (intersect(routes[i], routes[j])) {
                    graph.get(i).add(j);
                    graph.get(j).add(i);
                }
            }
        }

        Queue<Integer> queue = new ArrayDeque<>();
        int[] dist = new int[n];
        Arrays.fill(dist, -1);

        // populate initial queue and distances
        for (int i = 0; i < n; i++) {
            if (Arrays.binarySearch(routes[i], source) >= 0) {
                dist[i] = 1;
                queue.offer(i);
            }
        }

        while (!queue.isEmpty()) {
            int x = queue.poll();
            for (int y : graph.get(x)) {
                if (dist[y] == -1) {
                    dist[y] = dist[x] + 1;
                    if (Arrays.binarySearch(routes[y], target) >= 0) {
                        return dist[y];
                    }
                    queue.offer(y);
                }
            }
        }

        return -1;
    }

    private boolean intersect(int[] a, int[] b) {
        int i = 0, j = 0;
        while (i < a.length && j < b.length) {
            if (a[i] == b[j]) {
                return true;
            }
            if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }
        return false;
    }
}
