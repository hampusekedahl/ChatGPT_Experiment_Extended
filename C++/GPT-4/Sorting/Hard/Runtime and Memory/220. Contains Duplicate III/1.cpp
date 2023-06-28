#include <vector>
#include <set>
#include <algorithm>

using std::vector;
using std::set;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > indexDiff) {
                window.erase(nums[i - indexDiff - 1]);
            }
            auto it = window.lower_bound(static_cast<long long>(nums[i]) - valueDiff);
            if (it != window.end() && abs(*it - nums[i]) <= valueDiff) {
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};
