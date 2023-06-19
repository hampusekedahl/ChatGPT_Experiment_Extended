#include <vector>
#include <algorithm>
using namespace std;

class BIT {
    vector<int> bit;
    int n;

public:
    BIT(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    static int lowbit(int x) {
        return x & (-x);
    }

    int query(int x) {
        int res = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            res += bit[i];
        }
        return res;
    }

    void update(int x) {
        for (int i = x; i < n; i += lowbit(i)) {
            bit[i] += 1;
        }
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums(nums);
        sort(sorted_nums.begin(), sorted_nums.end());

        BIT bit(n);
        vector<int> res(n);

        for (int i = n - 1; i >= 0; --i) {
            int index = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]) - sorted_nums.begin() + 1;
            res[i] = bit.query(index - 1);
            bit.update(index);
        }

        return res;
    }
};
