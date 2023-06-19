#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> maxNum(k, 0);

        for (int i = max(0, k - n); i <= k && i <= m; ++i) {
            vector<int> candidate = merge(maxSingleArray(nums1, i), maxSingleArray(nums2, k - i));
            if (greater(candidate, 0, maxNum, 0)) {
                maxNum = candidate;
            }
        }

        return maxNum;
    }

    vector<int> maxSingleArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(k, 0);
        for (int i = 0, j = 0; i < n; ++i) {
            while (n - i > k - j && j > 0 && ans[j - 1] < nums[i]) {
                j--;
            }
            if (j < k) {
                ans[j++] = nums[i];
            }
        }
        return ans;
    }

    vector<int> merge(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> ans(nums1.size() + nums2.size(), 0);
        for (int i = 0, j = 0, r = 0; r < ans.size(); ++r) {
            ans[r] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        }
        return ans;
    }

    bool greater(const vector<int>& nums1, int i, const vector<int>& nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }
};
