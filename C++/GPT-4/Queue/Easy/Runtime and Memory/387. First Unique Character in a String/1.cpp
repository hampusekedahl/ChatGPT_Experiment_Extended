#include <vector>

class Solution {
public:
    int firstUniqChar(string s) {
        std::vector<int> charCount(26, 0);

        for (const char& c : s) {
            charCount[c - 'a']++;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (charCount[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
