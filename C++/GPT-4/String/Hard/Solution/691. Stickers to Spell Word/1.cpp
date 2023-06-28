class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size();
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (dp[mask] == -1) continue;
            for (string& sticker : stickers) {
                int now = mask;
                for (char letter : sticker) {
                    for (int i = 0; i < n; ++i) {
                        if (target[i] == letter && !((now >> i) & 1)) {
                            now |= 1 << i;
                            break;
                        }
                    }
                }
                if (dp[now] == -1 || dp[now] > dp[mask] + 1) {
                    dp[now] = dp[mask] + 1;
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
