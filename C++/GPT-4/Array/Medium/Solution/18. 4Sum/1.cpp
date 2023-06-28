class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if(n < 4) return result;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate number
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue; // skip duplicate number
                int l = j + 1, r = n - 1;
                while(l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum == target) {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l < r && nums[l] == nums[l + 1]) l++; // skip duplicate number
                        while(l < r && nums[r] == nums[r - 1]) r--; // skip duplicate number
                        l++;
                        r--;
                    }
                    else if(sum < target) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }
            }
        }
        return result;
    }
};
