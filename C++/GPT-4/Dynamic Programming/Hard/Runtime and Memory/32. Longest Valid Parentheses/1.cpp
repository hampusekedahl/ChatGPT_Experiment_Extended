#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        int maxLength = 0;
        std::stack<int> st;
        st.push(-1);

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    maxLength = std::max(maxLength, i - st.top());
                }
            }
        }

        return maxLength;
    }
};
