#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                // nums[mid] == nums[right], we cannot determine which part the minimum is in
                // so we reduce the search space by 1
                right--;
            }
        }
        
        return nums[left];
    }
};
