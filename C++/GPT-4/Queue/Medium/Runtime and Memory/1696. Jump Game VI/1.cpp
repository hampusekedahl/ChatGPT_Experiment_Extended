#include <vector>
#include <deque>

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dq.push_back(0);

        for (int i = 1; i < n; i++) {
            // when the front element is out of window, remove it
            if (dq.front() < i - k) {
                dq.pop_front();
            }
            
            // dp[i] is the maximum score to reach the end starting at i
            dp[i] = dp[dq.front()] + nums[i];

            // maintain the deque in decreasing order
            while (!dq.empty() && dp[i] >= dp[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        // the maximum score to reach the end starting at 0 is stored in dp[0]
        return dp[n - 1];
    }
};
