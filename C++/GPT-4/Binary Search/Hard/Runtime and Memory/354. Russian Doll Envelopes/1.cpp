#include <vector>
#include <algorithm>

class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        // Sort envelopes by width in ascending order and height in descending order
        std::sort(envelopes.begin(), envelopes.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
        });

        // Find the longest increasing subsequence (LIS) of heights
        std::vector<int> dp;
        for (const auto& envelope : envelopes) {
            int height = envelope[1];
            auto it = std::lower_bound(dp.begin(), dp.end(), height);
            if (it == dp.end()) {
                dp.push_back(height);
            } else {
                *it = height;
            }
        }

        return dp.size();
    }
};
