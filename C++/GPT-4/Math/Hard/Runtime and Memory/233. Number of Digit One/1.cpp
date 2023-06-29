class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for (long long d = 1; d <= n; d *= 10) {
            int digit = (n / d) % 10;
            count += (n / (d * 10)) * d;
            if (digit == 1)
                count += (n % d) + 1;
            else if (digit > 1)
                count += d;
        }
        return count;
    }
};
