class Solution {
    private HashMap<Integer, Integer> memo = new HashMap<>();

    public int integerReplacement(int n) {
        if (n == 1) return 0;
        if (memo.containsKey(n)) return memo.get(n);

        // when n is odd, try both n+1 and n-1, because we don't know which will lead to less steps.
        // (n & 1) is a bitwise AND operation that checks if the last binary digit of n is 1 (which means n is odd).
        if ((n & 1) == 1) {
            // Because Java doesn't handle unsigned integers, for maximum integer, we just calculate integerReplacement(n - 1) + 1
            if (n == Integer.MAX_VALUE) {
                memo.put(n, 2 + integerReplacement((n - 1) / 2));
            } else {
                memo.put(n, 2 + Math.min(integerReplacement((n + 1) / 2), integerReplacement((n - 1) / 2)));
            }
        } else {
            memo.put(n, 1 + integerReplacement(n / 2));
        }
        return memo.get(n);
    }
}
