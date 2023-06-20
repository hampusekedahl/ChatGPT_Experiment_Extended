import java.util.*;

class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer, Integer> map = new HashMap<>();
        Stack<Integer> stack = new Stack<>();
        
        // Iterate through nums2 in reverse order
        for (int i = nums2.length - 1; i >= 0; i--) {
            // Pop elements that are less than the current element
            while (!stack.isEmpty() && stack.peek() <= nums2[i]) {
                stack.pop();
            }
            
            // Associate the current element with the next greater element
            map.put(nums2[i], stack.isEmpty() ? -1 : stack.peek());
            
            // Push the current element onto the stack
            stack.push(nums2[i]);
        }
        
        // Replace elements in nums1 with their associated values
        for (int i = 0; i < nums1.length; i++) {
            nums1[i] = map.get(nums1[i]);
        }
        
        return nums1;
    }
}

