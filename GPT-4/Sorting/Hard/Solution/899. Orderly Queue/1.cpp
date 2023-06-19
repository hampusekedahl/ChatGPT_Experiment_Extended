#include <string>
#include <algorithm>

class Solution {
public:
    std::string orderlyQueue(std::string s, int k) {
        if (k >= 2) {
            std::sort(s.begin(), s.end());
            return s;
        } else {
            std::string min_str = s;
            for (int i = 0; i < s.length(); ++i) {
                s = s.substr(1) + s[0];
                min_str = std::min(min_str, s);
            }
            return min_str;
        }
    }
};
