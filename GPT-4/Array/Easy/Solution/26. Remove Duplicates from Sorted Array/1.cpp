#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int unique_count = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[unique_count] = nums[i];
                unique_count++;
            }
        }

        return unique_count;
    }
};
