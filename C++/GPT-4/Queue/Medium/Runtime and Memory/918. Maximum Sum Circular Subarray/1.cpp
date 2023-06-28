#include <algorithm>
#include <climits>

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT_MIN, minSum = INT_MAX;
        int curMax = 0, curMin = 0, totalSum = 0;

        for (int num : nums) {
            curMax = std::max(curMax + num, num);
            maxSum = std::max(maxSum, curMax);
            curMin = std::min(curMin + num, num);
            minSum = std::min(minSum, curMin);
            totalSum += num;
        }

        return maxSum > 0 ? std::max(maxSum, totalSum - minSum) : maxSum;
    }
};
