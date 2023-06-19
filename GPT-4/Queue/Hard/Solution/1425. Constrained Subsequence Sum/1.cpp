#include <vector>
#include <deque>

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq;

        int max_sum = INT_MIN;

        for (int i = 0; i < n; i++) {
            int max_prev = dq.empty() ? 0 : dp[dq.front()];
            dp[i] = max(nums[i], nums[i] + max_prev);

            while (!dq.empty() && dp[dq.back()] < dp[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i - dq.front() >= k) {
                dq.pop_front();
            }

            max_sum = max(max_sum, dp[i]);
        }

        return max_sum;
    }
};
