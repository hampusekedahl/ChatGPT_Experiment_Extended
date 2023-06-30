#include <unordered_map>

class Solution {
public:
    std::unordered_map<int, int> memo;

    int integerReplacement(int n) {
        // base case
        if (n == 1) {
            return 0;
        }
        
        // if value is already in memo
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        // if n is even
        if (n % 2 == 0) {
            memo[n] = 1 + integerReplacement(n / 2);
        } else { // if n is odd
            long long t = n; // to prevent integer overflow
            memo[n] = 2 + std::min(integerReplacement((t + 1) / 2), integerReplacement((t - 1) / 2));
        }

        return memo[n];
    }
};
