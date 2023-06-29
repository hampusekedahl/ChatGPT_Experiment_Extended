class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 2);
        for (int i = 1; i <= target; i++) {
            dp[i] = INT_MAX;
            int m = 1, j = 0;
            for (; m < i; m = (1 << ++j) - 1)
                for (int q = 0, p = 0; p < m; p = (1 << ++q) - 1)
                    dp[i] = min(dp[i], j + 1 + q + 1 + dp[i - (m - p)]);
            dp[i] = min(dp[i], j + (i == m ? 0 : 1 + dp[m - i]));
        }
        return dp[target];
    }
};
