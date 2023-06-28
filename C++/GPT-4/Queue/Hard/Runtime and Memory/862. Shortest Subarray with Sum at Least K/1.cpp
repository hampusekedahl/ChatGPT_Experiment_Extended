#include <deque>
#include <vector>
#include <climits>

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        int minLength = INT_MAX;
        deque<int> dq;

        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                minLength = std::min(minLength, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};
