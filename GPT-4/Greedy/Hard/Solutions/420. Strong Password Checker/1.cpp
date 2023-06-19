#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int strongPasswordChecker(string password) {
        int length = password.length();
        int insertions = 0, deletions = 0, replacements = 0;
        bool has_lower = false, has_upper = false, has_digit = false;
        int one = 0, two = 0;

        for (int i = 0; i < length;) {
            char c = password[i];
            int run_length = 1;
            has_lower |= islower(c);
            has_upper |= isupper(c);
            has_digit |= isdigit(c);

            while (i + run_length < length && password[i + run_length] == c) {
                run_length++;
            }

            if (run_length >= 3) {
                replacements += run_length / 3;
                one += run_length % 3 == 0;
                two += run_length % 3 == 1;
            }
            i += run_length;
        }

        if (length < 6) {
            insertions = 6 - length;
            return max(insertions, replacements);
        } else if (length <= 20) {
            return max(3 - (has_lower + has_upper + has_digit), replacements);
        } else {
            deletions = length - 20;
            replacements -= min(deletions, one) / 1;
            replacements -= min(max(deletions - one, 0), two * 2) / 2;
            replacements -= max(deletions - one - 2 * two, 0) / 3;
            return deletions + max(3 - (has_lower + has_upper + has_digit), replacements);
        }
    }
};
