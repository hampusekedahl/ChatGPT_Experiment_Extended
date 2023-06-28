#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff) {
        std::set<long long> window;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i > indexDiff) {
                window.erase(nums[i - indexDiff - 1]);
            }
            
            auto it = window.lower_bound(static_cast<long long>(nums[i]) - valueDiff);
            if (it != window.end() && *it <= static_cast<long long>(nums[i]) + valueDiff) {
                return true;
            }
            
            window.insert(nums[i]);
        }
        
        return false;
    }
};
