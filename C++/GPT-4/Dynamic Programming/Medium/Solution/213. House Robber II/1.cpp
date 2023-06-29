class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
private:
    int robRange(vector<int>& nums, int start, int end) {
        int pre = 0, cur = 0, temp;
        for (int i = start; i <= end; ++i) {
            temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
