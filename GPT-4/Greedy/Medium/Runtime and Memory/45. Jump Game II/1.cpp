#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int current_max_reachable = 0;
        int next_max_reachable = 0;

        for (int i = 0; i < n; ++i) {
            next_max_reachable = max(next_max_reachable, i + nums[i]);

            if (i == current_max_reachable) {
                ++jumps;
                current_max_reachable = next_max_reachable;

                if (current_max_reachable >= n - 1) {
                    break;
                }
            }
        }

        return jumps;
    }
};
