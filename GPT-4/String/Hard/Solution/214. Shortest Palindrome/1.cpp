#include <string>

class Solution {
public:
    std::string shortestPalindrome(std::string s) {
        int n = s.size();
        std::string reversed_s = s;
        std::reverse(reversed_s.begin(), reversed_s.end());
        std::string concat_s = s + "#" + reversed_s;

        std::vector<int> lps(concat_s.size(), 0);
        int j = 0;
        for (int i = 1; i < concat_s.size(); ++i) {
            while (j > 0 && concat_s[i] != concat_s[j]) {
                j = lps[j - 1];
            }
            if (concat_s[i] == concat_s[j]) {
                ++j;
            }
            lps[i] = j;
        }

        return reversed_s.substr(0, n - lps.back()) + s;
    }
};
