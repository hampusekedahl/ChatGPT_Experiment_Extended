import java.util.*;

class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        // Sort the envelopes by width in ascending order, and by height in descending order
        // when widths are the same.
        Arrays.sort(envelopes, new Comparator<int[]>() {
            public int compare(int[] e1, int[] e2) {
                if (e1[0] != e2[0]) {
                    return e1[0] - e2[0];
                } else {
                    return e2[1] - e1[1];
                }
            }
        });
        
        // Find the longest increasing subsequence based on height.
        List<Integer> dp = new ArrayList<>();
        for (int[] envelope : envelopes) {
            int height = envelope[1];
            if (dp.isEmpty() || height > dp.get(dp.size() - 1)) {
                dp.add(height);
            } else {
                int left = 0, right = dp.size() - 1;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (dp.get(mid) < height) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                dp.set(right, height);
            }
        }
        
        return dp.size();
    }
}

