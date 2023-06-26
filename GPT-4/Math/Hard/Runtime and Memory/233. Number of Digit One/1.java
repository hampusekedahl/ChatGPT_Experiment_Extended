class Solution {
    public int countDigitOne(int n) {
        if (n <= 0) {
            return 0;
        }
        int[] powerOf10 = new int[10];
        powerOf10[0] = 1;
        for (int i = 1; i < 10; ++i) {
            powerOf10[i] = powerOf10[i - 1] * 10;
        }
        int[] digit = new int[10];
        for (int i = 0; i < 10; ++i) {
            digit[i] = n / powerOf10[i] % 10;
        }
        int[][] dp = new int[10][2];
        dp[0][0] = digit[0] == 0 ? 0 : 1;
        dp[0][1] = 1;
        for (int i = 1; i < 10; ++i) {
            dp[i][0] = dp[i - 1][0] * 10;
            if (digit[i] == 0) {
                dp[i][0] += dp[i - 1][0] * (9 - 1);
            } else if (digit[i] == 1) {
                dp[i][0] += dp[i - 1][0] * (9 - 1) + dp[i - 1][1] + n % powerOf10[i] + 1;
            } else {
                dp[i][0] += dp[i - 1][0] * (9 - 1) + (digit[i] - 1) * dp[i - 1][1] + powerOf10[i];
            }
            dp[i][1] = dp[i - 1][1] * 10;
        }
        return dp[9][0];
    }
}

