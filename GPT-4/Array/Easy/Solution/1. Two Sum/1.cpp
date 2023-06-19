#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> complement_map;
        std::vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (complement_map.find(complement) != complement_map.end()) {
                result.push_back(complement_map[complement]);
                result.push_back(i);
                break;
            }
            complement_map[nums[i]] = i;
        }

        return result;
    }
};