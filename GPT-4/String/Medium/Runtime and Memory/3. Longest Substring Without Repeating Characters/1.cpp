#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int left = 0;
        unordered_map<char, int> charIndex;

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];

            // If the character is already in the map and its index is greater or equal to the left pointer
            if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= left) {
                left = charIndex[currentChar] + 1;
            }

            charIndex[currentChar] = right;
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
