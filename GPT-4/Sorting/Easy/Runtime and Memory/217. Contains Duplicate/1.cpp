#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> num_set;
        for (int num : nums) {
            if (num_set.count(num)) {
                return true;
            }
            num_set.insert(num);
        }
        return false;
    }
};
