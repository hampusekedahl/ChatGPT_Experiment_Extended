import java.util.*;

class Solution {
    public List<Integer> countSmaller(int[] nums) {
        int[] sorted = nums.clone();
        Arrays.sort(sorted);
        Map<Integer, Integer> ranks = new HashMap<>();
        List<Integer> result = new ArrayList<>();
        
        int rank = 0;
        for (int i = 0; i < sorted.length; i++) {
            if (i == 0 || sorted[i] != sorted[i - 1]) {
                ranks.put(sorted[i], ++rank);
            }
        }

        FenwickTree tree = new FenwickTree(ranks.size());
        for (int i = nums.length - 1; i >= 0; i--) {
            result.add(tree.query(ranks.get(nums[i]) - 1));
            tree.update(ranks.get(nums[i]), 1);
        }

        Collections.reverse(result);
        return result;
    }

    class FenwickTree {
        int[] tree;

        FenwickTree(int n) {
            tree = new int[n + 1];
        }

        public void update(int i, int delta) {
            while (i < tree.length) {
                tree[i] += delta;
                i += i & -i;
            }
        }

        public int query(int i) {
            int sum = 0;
            while (i > 0) {
                sum += tree[i];
                i -= i & -i;
            }
            return sum;
        }
    }
}
