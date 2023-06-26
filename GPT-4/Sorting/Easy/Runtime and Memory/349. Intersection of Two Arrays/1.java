import java.util.*;

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<Integer>();
        Set<Integer> resultSet = new HashSet<Integer>();
        
        // Add all elements of nums1 into the set1
        for (int num : nums1) {
            set1.add(num);
        }
        
        // If an element in nums2 exists in set1, add it to resultSet
        for (int num : nums2) {
            if (set1.contains(num)) {
                resultSet.add(num);
            }
        }
        
        // Convert resultSet to an array
        int[] result = new int[resultSet.size()];
        int index = 0;
        for (Integer num : resultSet) {
            result[index++] = num;
        }
        
        return result;
    }
}

