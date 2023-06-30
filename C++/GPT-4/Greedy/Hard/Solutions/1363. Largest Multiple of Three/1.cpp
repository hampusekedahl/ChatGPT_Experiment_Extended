#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string largestMultipleOfThree(std::vector<int>& digits) {
        int count[10] = {};
        int sum = 0;

        for (int digit : digits) {
            count[digit]++;
            sum += digit;
        }

        if (sum % 3 == 1) {  // if the sum of the digits modulo 3 equals 1
            if (!removeDigits(count, sum, 1)) {
                removeDigits(count, sum, 2);
            }
        } else if (sum % 3 == 2) {  // if the sum of the digits modulo 3 equals 2
            if (!removeDigits(count, sum, 2)) {
                removeDigits(count, sum, 1);
            }
        }

        std::string res = "";
        for (int i = 9; i >= 0; --i) {
            res += std::string(count[i], '0' + i);
        }

        if (!res.empty() && res[0] == '0') {
            return "0";
        }
        return res;
    }

private:
    bool removeDigits(int* count, int& sum, int mod) {
        for (int i = mod; i <= 9; i += 3) {
            if (count[i]) {
                count[i]--;
                sum -= i;
                return true;
            }
        }
        for (int i = 3 - mod; i <= 9; i += 3) {
            while (count[i]) {
                count[i]--;
                sum -= i;
                if (sum % 3 == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};
