#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string code) {
        std::stack<std::string> st;
        for (int i = 0; i < code.length(); ++i) {
            if (i > 0 && code[i - 1] == '<') {
                int j = i;
                while (j < code.length() && code[j] != '>') {
                    ++j;
                }
                std::string tag = code.substr(i, j - i);
                if (code[i - 2] != '/') {
                    st.push(tag);
                } else {
                    if (st.empty() || st.top() != tag) {
                        return false;
                    }
                    st.pop();
                }
                i = j;
            } else if (code.substr(i, 9) == "<![CDATA[") {
                int j = i + 9;
                while (j + 2 < code.length() && code.substr(j, 3) != "]]>") {
                    ++j;
                }
                if (j + 2 >= code.length()) {
                    return false;
                }
                i = j + 2;
            }
        }
        return st.empty();
    }
};
