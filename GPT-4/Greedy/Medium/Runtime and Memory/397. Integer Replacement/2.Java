class Solution {
    private HashMap<Long, Integer> memo = new HashMap<>();

    public int integerReplacement(int n) {
        if (n == 1) return 0;
        if (memo.containsKey((long) n)) return memo.get((long) n);

        if (n % 2 == 0) {
            memo.put((long) n, 1 + integerReplacement(n / 2));
        } else {
            memo.put((long) n, 2 + Math.min(integerReplacement(((long) n + 1) / 2), integerReplacement(((long) n - 1) / 2)));
        }
        return memo.get((long) n);
    }
}
