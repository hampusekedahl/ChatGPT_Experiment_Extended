#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        vector<bool> is_prime(n, true);
        is_prime[0] = false;
        is_prime[1] = false;

        for (int i = 2; i * i < n; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        int prime_count = 0;
        for (bool prime : is_prime) {
            if (prime) {
                prime_count++;
            }
        }

        return prime_count;
    }
};
