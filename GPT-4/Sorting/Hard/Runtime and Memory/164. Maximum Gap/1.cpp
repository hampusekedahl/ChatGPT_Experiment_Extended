#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int max_num = *max_element(nums.begin(), nums.end());
        int exp = 1;
        vector<int> buffer(n);

        while (max_num / exp > 0) {
            vector<int> count(10, 0);

            for (int i = 0; i < n; i++) {
                int index = (nums[i] / exp) % 10;
                count[index]++;
            }

            for (int i = 1; i < 10; i++) {
                count[i] += count[i - 1];
            }

            for (int i = n - 1; i >= 0; i--) {
                int index = (nums[i] / exp) % 10;
                buffer[--count[index]] = nums[i];
            }

            nums = buffer;
            exp *= 10;
        }

        int max_gap = 0;
        for (int i = 1; i < n; i++) {
            max_gap = std::max(max_gap, nums[i] - nums[i - 1]);
        }

        return max_gap;
    }
};
