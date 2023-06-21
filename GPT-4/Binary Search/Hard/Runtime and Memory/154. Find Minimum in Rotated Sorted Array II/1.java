class Solution {
    public int findMin(int[] nums) {
        int low = 0;
        int high = nums.length - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;

            // if mid element is greater than high, minimum is in the right part
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } 
            // if mid element is less than high, minimum is in the left part
            else if (nums[mid] < nums[high]) {
                high = mid;
            } 
            // when nums[mid] and nums[high] are same, we aren't sure about the position of minimum element,
            // so decrease the search space by one.
            else {
                high--;
            }
        }
        return nums[low];
    }
}

