#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int lastWordLength = 0;
        int index = s.length() - 1;

        // Skip trailing spaces
        while (index >= 0 && s[index] == ' ') {
            index--;
        }

        // Count the characters in the last word
        while (index >= 0 && s[index] != ' ') {
            lastWordLength++;
            index--;
        }

        return lastWordLength;
    }
};
