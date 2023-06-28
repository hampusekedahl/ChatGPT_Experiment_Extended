#include <string>

using std::string;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int tail = s.length() - 1;

        // Move the tail pointer to the end of the last word
        while (tail >= 0 && s[tail] == ' ') {
            tail--;
        }

        // Count the characters in the last word
        while (tail >= 0 && s[tail] != ' ') {
            length++;
            tail--;
        }

        return length;
    }
};