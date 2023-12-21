import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public List<String> removeInvalidParentheses(String s) {
        int left = 0, right = 0;

        // Find the number of misplaced parentheses
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(') {
                ++left;
            } else if (s.charAt(i) == ')') {
                if (left != 0) {
                    --left;
                } else {
                    ++right;
                }
            }
        }

        Set<String> ans = new HashSet<>();
        dfs(s, 0, left, right, 0, new StringBuilder(), ans);

        return new ArrayList<>(ans);
    }

    private void dfs(String s, int i, int left, int right, int open, StringBuilder sb, Set<String> ans) {
        if (left < 0 || right < 0 || open < 0) {
            return;
        }

        if (i == s.length()) {
            if (left == 0 && right == 0 && open == 0) {
                ans.add(sb.toString());
            }
            return;
        }

        char c = s.charAt(i);
        int len = sb.length();

        if (c == '(') {
            dfs(s, i + 1, left - 1, right, open, sb, ans);  // remove (
            dfs(s, i + 1, left, right, open + 1, sb.append(c), ans);  // keep (
        } else if (c == ')') {
            dfs(s, i + 1, left, right - 1, open, sb, ans);  // remove )
            dfs(s, i + 1, left, right, open - 1, sb.append(c), ans);  // keep )
        } else {
            dfs(s, i + 1, left, right, open, sb.append(c), ans);  // non-parenthesis characters
        }

        sb.setLength(len);  // reset string builder
    }
}

