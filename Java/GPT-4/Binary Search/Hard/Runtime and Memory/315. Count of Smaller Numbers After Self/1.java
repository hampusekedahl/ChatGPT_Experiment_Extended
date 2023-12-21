import java.util.*;

class Solution {
    int[] bit;
    int n;
    public List<Integer> countSmaller(int[] nums) {
        // discretization
        Set<Integer> set = new TreeSet<>();
        for (int num : nums) {
            set.add(num);
        }

        Map<Integer, Integer> rank = new HashMap<>();
        int rankNum = 1;
        for (int num : set) {
            rank.put(num, rankNum++);
        }

        List<Integer> result = new ArrayList<>();
        bit = new int[rankNum];
        n = rankNum - 1;
        for (int i = nums.length - 1; i >= 0; --i) {
            int r = rank.get(nums[i]);
            result.add(query(r - 1));
            update(r);
        }
        Collections.reverse(result);
        return result;
    }

    private void update(int i) {
        while (i <= n) {
            bit[i] += 1;
            i += i & -i;
        }
    }

    private int query(int i) {
        int res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
}

