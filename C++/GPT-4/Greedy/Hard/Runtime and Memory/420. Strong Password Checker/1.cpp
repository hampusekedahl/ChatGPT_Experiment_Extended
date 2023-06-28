#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int strongPasswordChecker(string password) {
        int len = password.length();
        bool hasLower = false, hasUpper = false, hasDigit = false;
        int replaceCount = 0, oneMod = 0, twoMod = 0;

        for (int i = 0; i < len;) {
            char c = password[i];
            if (isdigit(c)) hasDigit = true;
            if (islower(c)) hasLower = true;
            if (isupper(c)) hasUpper = true;

            int j = i;
            while (i < len && password[i] == c) i++;
            int length = i - j;
            if (length >= 3) {
                replaceCount += length / 3;
                if (length % 3 == 0) {
                    oneMod++;
                } else if (length % 3 == 1) {
                    twoMod++;
                }
            }
        }

        int missingChars = (!hasLower) + (!hasUpper) + (!hasDigit);

        if (len < 6) {
            return max(missingChars, 6 - len);
        } else if (len <= 20) {
            return max(missingChars, replaceCount);
        } else {
            int deleteCount = len - 20;
            replaceCount -= min(deleteCount, oneMod * 1) / 1;
            replaceCount -= min(max(deleteCount - oneMod, 0), twoMod * 2) / 2;
            replaceCount -= max(deleteCount - oneMod - 2 * twoMod, 0) / 3;
            return deleteCount + max(missingChars, replaceCount);
        }
    }
};
