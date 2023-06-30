class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) return NestedInteger();
        if (s[0] != '[') return NestedInteger(stoi(s));
        if (s.size() <= 2) return NestedInteger();
        
        NestedInteger result;
        int start = 1, count = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (count == 0 && (s[i] == ',' || i == s.size() - 1)) {
                result.add(deserialize(s.substr(start, i - start)));
                start = i + 1;
            } else if (s[i] == '[') ++count;
            else if (s[i] == ']') --count;
        }
        
        return result;
    }
};
