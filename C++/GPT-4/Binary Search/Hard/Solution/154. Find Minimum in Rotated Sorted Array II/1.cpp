#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while (left < right) {
            mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else { // If nums[mid] == nums[right], we can't determine which side the minimum element is on
                right--; // Decrease the search space by one, this might cause the algorithm to degrade to O(n) in the worst case
            }
        }

        // When left and right converge, we have found the minimum element.
        return nums[left];
    }
};
