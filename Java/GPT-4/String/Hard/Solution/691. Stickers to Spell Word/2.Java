import java.util.*;

class Solution {
    int[] targetCount;
    int[][] stickersCount;
    Map<String, Integer> memo;
    
    public int minStickers(String[] stickers, String target) {
        int m = stickers.length;
        targetCount = new int[26];
        memo = new HashMap<>();
        stickersCount = new int[m][26];
        
        // count characters in target
        for (char c : target.toCharArray()) targetCount[c-'a']++;
        
        // count characters in stickers
        for (int i = 0; i < m; i++) {
            for (char c : stickers[i].toCharArray()) stickersCount[i][c-'a']++;
        }
        
        memo.put("", 0);
        return helper(memo, stickersCount, target);
    }
    
    private int helper(Map<String, Integer> memo, int[][] stickersCount, String target) {
        if (memo.containsKey(target)) return memo.get(target);
        int[] targetCount = new int[26];
        for (char c : target.toCharArray()) targetCount[c-'a']++;
        
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < stickersCount.length; i++) {
            // optimization: skip sticker that does not contain the first char of target
            if (stickersCount[i][target.charAt(0) - 'a'] == 0) continue;
            
            StringBuilder sb = new StringBuilder();
            // apply a sticker on every character a-z
            for (int j = 0; j < 26; j++) {
                if (targetCount[j] > 0 ) {
                    for (int k = 0; k < Math.max(0, targetCount[j] - stickersCount[i][j]); k++) {
                        sb.append((char)('a' + j));
                    }
                }
            }
            
            String s = sb.toString();
            int temp = helper(memo, stickersCount, s);
            
            if (temp != -1) ans = Math.min(ans, 1+temp);
        }
        
        memo.put(target, ans == Integer.MAX_VALUE? -1: ans);
        return memo.get(target);
    }
}
