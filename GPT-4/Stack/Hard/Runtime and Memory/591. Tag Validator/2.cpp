#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string code) {
        stack<string> tagStack;
        int i = 0;
        while (i < code.size()) {
            if (code[i] == '<') {
                int closeIndex = code.find('>', i + 1);
                if (closeIndex == string::npos)
                    return false;

                string tag = code.substr(i + 1, closeIndex - i - 1);
                i = closeIndex + 1;

                if (tag.substr(0, 8) == "![CDATA[") {
                    int endCdata = code.find("]]>", i);
                    if (endCdata == string::npos)
                        return false;
                    i = endCdata + 3;
                } else {
                    if (tag[0] == '/') {
                        if (tagStack.empty() || tagStack.top() != tag.substr(1))
                            return false;
                        tagStack.pop();
                    } else {
                        if (!isValidTagName(tag))
                            return false;
                        tagStack.push(tag);
                    }
                }
            } else {
                if (tagStack.empty()) {
                    return false;
                }
                i++;
            }
        }

        return tagStack.empty();
    }

private:
    bool isValidTagName(const string& tag) {
        if (tag.empty() || tag.size() > 9)
            return false;

        for (char c : tag) {
            if (c < 'A' || c > 'Z')
                return false;
        }

        return true;
    }
};
