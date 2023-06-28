#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int total_sum = 0;
        int max_sum = nums[0], cur_max_sum = 0;
        int min_sum = nums[0], cur_min_sum = 0;

        for (int num : nums) {
            cur_max_sum = std::max(cur_max_sum + num, num);
            max_sum = std::max(max_sum, cur_max_sum);

            cur_min_sum = std::min(cur_min_sum + num, num);
            min_sum = std::min(min_sum, cur_min_sum);

            total_sum += num;
        }

        if (max_sum > 0)
            return std::max(max_sum, total_sum - min_sum);
        else
            return max_sum;
    }
};
