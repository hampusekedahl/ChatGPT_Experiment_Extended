class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size(); // Ensure k is within the array size
        
        reverse(nums, 0, nums.size() - 1); // Reverse entire array
        reverse(nums, 0, k - 1); // Reverse first k elements
        reverse(nums, k, nums.size() - 1); // Reverse remaining elements
    }

private:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};
