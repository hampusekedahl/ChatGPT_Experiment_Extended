class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= target; ++i) {
            int m = log2(i) + 1;  // count of 'A's to reach 'i' by going forward
            if (1 << m == i + 1) {  // position is at 'i'
                dp[i] = m;
            } else {
                // case 1: use 'm' A's to get past 'i' and reverse
                for (int j = 0; j < m - 1; ++j) {
                    dp[i] = min(dp[i], m + j + 1 + dp[i - (1 << m - 1) + (1 << j)]);
                }
                // case 2: use 'm - 1' A's to get just before 'i', reverse, go back some distance, and reverse again
                if ((1 << m) - 1 - i < i) {
                    dp[i] = min(dp[i], m + m - 1 + 1 + dp[(1 << m) - 1 - i]);
                }
            }
        }
        return dp[target];
    }
};
