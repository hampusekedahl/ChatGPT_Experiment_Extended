#include <string>

using std::string;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        string reversed_s = s;
        reverse(reversed_s.begin(), reversed_s.end());
        string combined = s + "#" + reversed_s;

        vector<int> prefix_table = computePrefixTable(combined);
        string suffix = s.substr(prefix_table.back());
        reverse(suffix.begin(), suffix.end());

        return suffix + s;
    }

private:
    vector<int> computePrefixTable(const string& s) {
        int n = s.length();
        vector<int> prefix_table(n, 0);

        int j = 0;
        for (int i = 1; i < n; i++) {
            while (j > 0 && s[i] != s[j]) {
                j = prefix_table[j - 1];
            }

            if (s[i] == s[j]) {
                j++;
            }

            prefix_table[i] = j;
        }

        return prefix_table;
    }
};
