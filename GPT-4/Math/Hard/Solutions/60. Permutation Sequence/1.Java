class Solution {
    private boolean[] used;
    private int[] factorial;
    private int n;
    private int k;

    public String getPermutation(int n, int k) {
        this.n = n;
        this.k = k;
        calculateFactorial(n);

        // lookup table for this problem
        used = new boolean[n + 1];
        for (int i = 0; i < n + 1; i++) {
            used[i] = false;
        }

        StringBuilder path = new StringBuilder();
        dfs(0, path);
        return path.toString();
    }

    // DFS
    private void dfs(int index, StringBuilder path) {
        if (index == n) {
            return;
        }

        int cnt = factorial[n - index - 1];  // count the remaining permutations
        for (int i = 1; i <= n; i++) {
            if (used[i]) {
                continue;
            }
            if (cnt < k) {
                k -= cnt;
                continue;
            }
            path.append(i);
            used[i] = true;
            dfs(index + 1, path);
            return;
        }
    }

    // Calculate factorial
    private void calculateFactorial(int n) {
        factorial = new int[n + 1];
        factorial[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
    }
}
