#include <vector>
#include <string>
#include <climits>
#include <algorithm>

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int m = target.size();
        int n = 1 << m; // number of all subsets of target characters
        vector<int> dp(n, INT_MAX); // dp[i] is the min number of stickers to spell out the subset of target represented by i
        dp[0] = 0; // 0 subset corresponds to empty string

        // Preprocess each sticker, counting character occurrences
        for (auto& s : stickers) {
            std::sort(s.begin(), s.end());
        }

        for (int i = 0; i < n; i++) { // for every subset i
            if (dp[i] == INT_MAX) continue;

            for (string& sticker : stickers) { // try every sticker
                int cur = i;
                for (char c : sticker) { // for characters in current sticker
                    for (int r = 0; r < m; r++) { // try to match each character in the subset
                        if (target[r] == c && !((cur >> r) & 1)) { // if character matches and this character in subset is not used yet
                            cur |= 1 << r;
                            break;
                        }
                    }
                }
                dp[cur] = min(dp[cur], dp[i] + 1); // update the minimum stickers needed for the new subset
            }
        }

        return dp[n - 1] == INT_MAX ? -1 : dp[n - 1];
    }
};
