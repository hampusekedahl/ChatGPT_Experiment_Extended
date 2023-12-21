import java.util.*;

class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
        TreeSet<Long> set = new TreeSet<>();
        for (int i = 0; i < nums.length; ++i) {
            Long s = set.ceiling((long) nums[i]);
            if (s != null && s <= nums[i] + valueDiff) return true;

            Long g = set.floor((long) nums[i]);
            if (g != null && nums[i] <= g + valueDiff) return true;

            set.add((long) nums[i]);
            if (set.size() > indexDiff) {
                set.remove((long) nums[i - indexDiff]);
            }
        }
        return false;
    }
}
