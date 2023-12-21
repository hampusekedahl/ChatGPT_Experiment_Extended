class Solution {
    private HashMap<Long, Integer> memo = new HashMap<>();

    public int integerReplacement(int n) {
        return integerReplacement((long)n);
    }

    private int integerReplacement(long n) {
        if (n == 1) return 0;
        if (memo.containsKey(n)) return memo.get(n);

        if (n % 2 == 0) {
            memo.put(n, 1 + integerReplacement(n / 2));
        } else {
            memo.put(n, 2 + Math.min(integerReplacement((n + 1) / 2), integerReplacement((n - 1) / 2)));
        }
        return memo.get(n);
    }
}
