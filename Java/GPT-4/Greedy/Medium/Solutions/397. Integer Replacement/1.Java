class Solution {
    public int integerReplacement(int n) {
        return integerReplacement((long)n);
    }
    
    private int integerReplacement(long n) {
        if (n == 1) {
            return 0;
        } else if (n % 2 == 0) {
            return 1 + integerReplacement(n / 2);
        } else {
            return 1 + Math.min(integerReplacement(n + 1), integerReplacement(n - 1));
        }
    }
}
