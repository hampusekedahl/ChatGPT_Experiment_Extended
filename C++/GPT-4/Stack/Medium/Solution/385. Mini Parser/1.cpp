class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) return NestedInteger();
        if (s[0] != '[') return NestedInteger(stoi(s));
        stack<NestedInteger> stk;
        int start = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[') {
                stk.push(NestedInteger());
                start = i + 1;
            } else if (s[i] == ',' || s[i] == ']') {
                if (i > start) {
                    stk.top().add(NestedInteger(stoi(s.substr(start, i - start))));
                }
                start = i + 1;
                if (s[i] == ']') {
                    if (stk.size() > 1) {
                        NestedInteger t = stk.top(); stk.pop();
                        stk.top().add(t);
                    }
                }
            }
        }
        return stk.top();
    }
};
