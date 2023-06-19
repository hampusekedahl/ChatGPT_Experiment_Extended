#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int s_len = s.length(), t_len = t.length();
        int s_idx = 0, t_idx = 0;

        while (s_idx < s_len && t_idx < t_len) {
            if (s[s_idx] == t[t_idx]) {
                s_idx++;
            }
            t_idx++;
        }

        return s_idx == s_len;
    }
};
