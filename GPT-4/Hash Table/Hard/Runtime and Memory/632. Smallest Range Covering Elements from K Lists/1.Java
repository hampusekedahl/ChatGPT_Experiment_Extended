import java.util.*;

class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[2]));
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE, start = 0, end = Integer.MAX_VALUE;

        for (int i = 0; i < nums.size(); i++) {
            minHeap.offer(new int[]{i, 0, nums.get(i).get(0)});
            max = Math.max(max, nums.get(i).get(0));
        }

        while (minHeap.size() == nums.size()) {
            int[] curr = minHeap.poll();
            if (end - start > max - curr[2]) {
                start = curr[2];
                end = max;
            }

            if (curr[1] + 1 < nums.get(curr[0]).size()) {
                curr[1]++;
                curr[2] = nums.get(curr[0]).get(curr[1]);
                minHeap.offer(curr);
                max = Math.max(max, curr[2]);
            }
        }

        return new int[]{start, end};
    }
}
