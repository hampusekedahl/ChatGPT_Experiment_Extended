#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int maximumGap(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int min_val = *std::min_element(nums.begin(), nums.end());
        int max_val = *std::max_element(nums.begin(), nums.end());
        int bucket_size = std::max(1, (max_val - min_val) / (n - 1));
        int bucket_count = (max_val - min_val) / bucket_size + 1;

        std::vector<int> bucket_min(bucket_count, std::numeric_limits<int>::max());
        std::vector<int> bucket_max(bucket_count, std::numeric_limits<int>::min());

        for (int num : nums) {
            int idx = (num - min_val) / bucket_size;
            bucket_min[idx] = std::min(bucket_min[idx], num);
            bucket_max[idx] = std::max(bucket_max[idx], num);
        }

        int max_gap = 0;
        int prev_max = min_val;

        for (int i = 0; i < bucket_count; ++i) {
            if (bucket_min[i] == std::numeric_limits<int>::max()) continue;
            max_gap = std::max(max_gap, bucket_min[i] - prev_max);
            prev_max = bucket_max[i];
        }

        return max_gap;
    }
};
