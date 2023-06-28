#include <iostream>
#include <limits>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int reversed = 0;
        int original = x;

        while (x > 0) {
            int last_digit = x % 10;
            x /= 10;

            if (reversed > std::numeric_limits<int>::max() / 10 ||
                (reversed == std::numeric_limits<int>::max() / 10 && last_digit > std::numeric_limits<int>::max() % 10)) {
                return false;
            }

            reversed = reversed * 10 + last_digit;
        }

        return original == reversed;
    }
};