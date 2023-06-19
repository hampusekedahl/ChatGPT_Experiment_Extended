#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Find the next alphanumeric character from the left
            while (left < right && !std::isalnum(s[left])) {
                left++;
            }

            // Find the next alphanumeric character from the right
            while (left < right && !std::isalnum(s[right])) {
                right--;
            }

            // Compare the characters, case-insensitive
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
