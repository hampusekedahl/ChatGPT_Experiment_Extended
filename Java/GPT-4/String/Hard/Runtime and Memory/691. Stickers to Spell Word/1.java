import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int minStickers(String[] stickers, String target) {
        int n = stickers.length;
        int[][] stickerCount = new int[n][26];
        Map<String, Integer> dp = new HashMap<>();
        dp.put("", 0);

        // Create frequency array for stickers
        for (int i = 0; i < n; i++) {
            for (char c : stickers[i].toCharArray()) {
                stickerCount[i][c - 'a']++;
            }
        }

        return helper(dp, stickerCount, target);
    }

    private int helper(Map<String, Integer> dp, int[][] stickerCount, String target) {
        if (dp.containsKey(target)) {
            return dp.get(target);
        }

        int[] targetCount = new int[26];
        for (char c : target.toCharArray()) {
            targetCount[c - 'a']++;
        }

        int ans = Integer.MAX_VALUE;
        int n = stickerCount.length;

        for (int i = 0; i < n; i++) {
            // Optimization: skip sticker that does not contain target's first character
            if (stickerCount[i][target.charAt(0) - 'a'] == 0) continue;

            StringBuilder sb = new StringBuilder();
            // Use this sticker as many times as possible
            for (int j = 0; j < 26; j++) {
                if (targetCount[j] > 0) {
                    for (int k = 0; k < Math.max(0, targetCount[j] - stickerCount[i][j]); k++) {
                        sb.append((char) ('a' + j));
                    }
                }
            }
            String s = sb.toString();
            int tmp = helper(dp, stickerCount, s);
            if (tmp != -1) {
                ans = Math.min(ans, 1 + tmp);
            }
        }

        dp.put(target, ans == Integer.MAX_VALUE ? -1 : ans);
        return dp.get(target);
    }
}
