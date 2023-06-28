#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> num_set;
        
        for (int num : nums) {
            if (num_set.find(num) != num_set.end()) {
                return true;
            }
            num_set.insert(num);
        }
        
        return false;
    }
};
