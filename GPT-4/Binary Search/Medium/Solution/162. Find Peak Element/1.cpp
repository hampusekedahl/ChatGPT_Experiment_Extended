#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while (left < right) {
            mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1]) {
                right = mid; // If the current element is greater than the next one, there is a peak element in the left half.
            } else {
                left = mid + 1; // If the current element is smaller than the next one, there is a peak element in the right half.
            }
        }

        // When left and right converge, we have found a peak element.
        return left;
    }
};
