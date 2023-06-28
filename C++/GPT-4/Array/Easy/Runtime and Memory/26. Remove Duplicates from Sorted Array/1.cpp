#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int unique_ptr = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[unique_ptr]) {
                unique_ptr++;
                nums[unique_ptr] = nums[i];
            }
        }

        return unique_ptr + 1;
    }
};
