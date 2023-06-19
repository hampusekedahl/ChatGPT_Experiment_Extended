#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> char_count(26, 0);

        for (char c : s) {
            char_count[c - 'a']++;
        }

        for (char c : t) {
            char_count[c - 'a']--;
            if (char_count[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
