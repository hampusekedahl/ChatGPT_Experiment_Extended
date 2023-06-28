#include <vector>
#include <stack>
#include <limits>

class Solution {
public:
    bool find132pattern(std::vector<int>& nums) {
        int third = std::numeric_limits<int>::min();
        std::stack<int> st;

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < third) {
                return true;
            }
            while (!st.empty() && nums[i] > st.top()) {
                third = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        
        return false;
    }
};
