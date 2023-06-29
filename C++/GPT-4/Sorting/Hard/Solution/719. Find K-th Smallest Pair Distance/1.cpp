#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // sort the numbers
        sort(nums.begin(), nums.end());

        // binary search
        int low = 0;
        int high = nums.back() - nums.front();

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0, left = 0;

            // use two pointers to find the number of pairs
            for (int right = 0; right < nums.size(); ++right) {
                while (nums[right] - nums[left] > mid) {
                    ++left;
                }
                count += right - left;
            }

            // adjust the binary search bounds
            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
