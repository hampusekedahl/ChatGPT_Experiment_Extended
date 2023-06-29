class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 2, INT_MAX);
        dp[0] = 0; dp[1] = 1; dp[2] = 4;

        for (int t = 3; t <= target; ++t) {
            int n = log2(t) + 1, left = pow(2, n) - 1;
            if (t == left) {
                dp[t] = n;
            } else {
                for (int j = 0; j < n - 1; ++j) {
                    dp[t] = min(dp[t], dp[t - pow(2, n - 1) + pow(2, j)] + n - 1 + j + 2);
                }
                if (left - t < t) {
                    dp[t] = min(dp[t], dp[left - t] + n + 1);
                }
            }
        }
        return dp[target];
    }
};
