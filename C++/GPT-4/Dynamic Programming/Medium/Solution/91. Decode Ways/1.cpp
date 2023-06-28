#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        int n = s.length();
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            int one_digit = stoi(s.substr(i - 1, 1));
            int two_digits = stoi(s.substr(i - 2, 2));

            if (one_digit >= 1) {
                dp[i] += dp[i - 1];
            }

            if (two_digits >= 10 && two_digits <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};
