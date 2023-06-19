#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int maxLength = 0;
        int left = 0;
        int right = 0;
        std::unordered_map<char, int> charIndexMap;

        while (right < s.length()) {
            if (charIndexMap.find(s[right]) != charIndexMap.end() && charIndexMap[s[right]] >= left) {
                left = charIndexMap[s[right]] + 1;
            }

            charIndexMap[s[right]] = right;
            maxLength = std::max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};
