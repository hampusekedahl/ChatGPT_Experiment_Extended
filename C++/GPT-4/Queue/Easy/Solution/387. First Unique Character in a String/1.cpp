#include <unordered_map>
#include <string>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> charCount;

        // Count the occurrences of each character in the string.
        for (char c : s) {
            charCount[c]++;
        }

        // Iterate through the string again and find the first non-repeating character.
        for (int i = 0; i < s.length(); i++) {
            if (charCount[s[i]] == 1) {
                return i;
            }
        }

        // If no such character exists, return -1.
        return -1;
    }
};
