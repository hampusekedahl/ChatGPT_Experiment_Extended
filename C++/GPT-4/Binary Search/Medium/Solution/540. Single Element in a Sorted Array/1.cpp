#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while (left < right) {
            mid = left + (right - left) / 2;

            // Check if the mid index is even or odd
            bool isEven = (right - mid) % 2 == 0;

            // If the current element is equal to the next one
            if (nums[mid] == nums[mid + 1]) {
                if (isEven) {
                    left = mid + 2; // The single element is in the right half
                } else {
                    right = mid - 1; // The single element is in the left half
                }
            }
            // If the current element is equal to the previous one
            else if (nums[mid] == nums[mid - 1]) {
                if (isEven) {
                    right = mid - 2; // The single element is in the left half
                } else {
                    left = mid + 1; // The single element is in the right half
                }
            } else {
                // If the current element is not equal to the previous or next one, it's the single element
                return nums[mid];
            }
        }

        // When left and right converge, we have found the single element.
        return nums[left];
    }
};
