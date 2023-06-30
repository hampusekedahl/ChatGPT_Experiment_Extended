#include<unordered_map>
#include<limits.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> memo;

    int integerReplacement(int n) {
        // Base case
        if(n == 1) return 0;

        // If n is in the memo, return the stored value
        if(memo.find(n) != memo.end()) return memo[n];

        // Calculate and store the result for n
        if(n % 2 == 0) {
            memo[n] = 1 + integerReplacement(n / 2);
        } else {
            // Need to use long long here because n+1 can overflow if n is INT_MAX
            long long N = n;
            memo[n] = 2 + min(integerReplacement((N - 1) / 2), integerReplacement((N + 1) / 2));
        }

        // Return the result
        return memo[n];
    }
};
