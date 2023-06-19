#include <string>
#include <stack>
#include <iostream>

class Solution {
public:
    bool isValidTagName(const std::string& tagName) {
        int n = tagName.size();
        if (n < 1 || n > 9) return false;
        for (char c : tagName) {
            if (c < 'A' || c > 'Z') return false;
        }
        return true;
    }
    
    bool isValid(std::string code) {
        std::stack<std::string> st;
        int i = 0;
        while (i < code.length()) {
            if (i > 0 && code[i - 1] == '<') {
                int j = i;
                while (j < code.length() && code[j] != '>') {
                    ++j;
                }
                if (j == code.length()) return false;
                std::string tag = code.substr(i, j - i);
                if (code[i - 2] != '/') {
                    if (!isValidTagName(tag)) return false;
                    st.push(tag);
                } else {
                    if (st.empty() || st.top() != tag || !isValidTagName(tag)) {
                        return false;
                    }
                    st.pop();
                }
                i = j;
            } else if (i + 8 < code.length() && code.substr(i, 9) == "<![CDATA[") {
                int j = i + 9;
                while (j + 2 < code.length() && code.substr(j, 3) != "]]>") {
                    ++j;
                }
                if (j + 2 >= code.length()) {
                    return false;
                }
                i = j + 2;
            } else {
                i++;
            }
        }
        return st.empty();
    }
};


