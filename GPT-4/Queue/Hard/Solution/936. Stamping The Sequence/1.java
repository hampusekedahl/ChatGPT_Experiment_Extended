import java.util.*;

class Solution {
    public int[] movesToStamp(String stamp, String target) {
        char[] s = stamp.toCharArray(), t = target.toCharArray();
        List<Integer> res = new ArrayList<>();
        boolean[] visited = new boolean[t.length];
        int stars = 0;

        while(stars < t.length) {
            boolean doneReplace = false;
            for (int i = 0; i <= t.length - s.length; i++) {
                if (!visited[i] && canReplace(t, i, s)) {
                    stars = doReplace(t, i, s.length, stars);
                    doneReplace = true;
                    res.add(i);
                    visited[i] = true;
                    if(stars == t.length) {
                        break;
                    }
                }
            }

            if (!doneReplace) {
                return new int[0];
            }
        }

        Collections.reverse(res);
        return res.stream().mapToInt(i->i).toArray();
    }

    private boolean canReplace(char[] t, int p, char[] s) {
        for (int i = 0; i < s.length; i++) {
            if (t[i + p] != '*' && t[i + p] != s[i]) {
                return false;
            }
        }
        return true;
    }

    private int doReplace(char[] t, int p, int len, int count) {
        for (int i = 0; i < len; i++) {
            if (t[i + p] != '*') {
                t[i + p] = '*';
                count++;
            }
        }
        return count;
    }
}

