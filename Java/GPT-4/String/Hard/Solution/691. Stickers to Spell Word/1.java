class Solution {
    public int minStickers(String[] stickers, String target) {
        int m = stickers.length;
        int n = target.length();
        int[] dp = new int[1 << n];
        int[][] stickersCnt = new int[m][26];
        int[] targetCnt = new int[26];
        for (String s : stickers) {
            for (char c : s.toCharArray()) {
                stickersCnt[s.indexOf(s)][c - 'a']++;
            }
        }
        for (char c : target.toCharArray()) {
            targetCnt[c - 'a']++;
        }
        Arrays.fill(dp, -1);
        dp[0] = 0;
        for (int i = 0; i < (1 << n); i++) {
            if (dp[i] == -1) {
                continue;
            }
            for (int j = 0; j < m; j++) {
                int[] temp = Arrays.copyOf(targetCnt, 26);
                int sup = i;
                for (char c : stickers[j].toCharArray()) {
                    for (int k = 0; k < n; k++) {
                        if (sup >> k % 2 == 1 && target.charAt(k) == c && temp[c - 'a'] > 0) {
                            sup ^= (1 << k);
                            temp[c - 'a']--;
                        }
                    }
                }
                dp[sup] = dp[sup] == -1 ? dp[i] + 1 : Math.min(dp[sup], dp[i] + 1);
            }
        }
        return dp[(1 << n) - 1];
    }
}
