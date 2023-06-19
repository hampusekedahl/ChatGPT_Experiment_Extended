#include <vector>
#include <stack>
#include <limits>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }

        vector<int> min_left(n);
        min_left[0] = nums[0];

        // Find the minimum element to the left of each element
        for (int i = 1; i < n; ++i) {
            min_left[i] = min(min_left[i - 1], nums[i]);
        }

        stack<int> stk;

        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > min_left[i]) {
                // Keep popping until we find an element smaller than min_left[i]
                while (!stk.empty() && stk.top() <= min_left[i]) {
                    stk.pop();
                }

                // If the stack is not empty, we found a 132 pattern
                if (!stk.empty() && stk.top() < nums[i]) {
                    return true;
                }

                // Push the current element onto the stack
                stk.push(nums[i]);
            }
        }

        return false;
    }
};
