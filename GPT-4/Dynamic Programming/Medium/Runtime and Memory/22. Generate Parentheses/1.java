import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> combinations = new ArrayList<>();
        backtrack(combinations, "", 0, 0, n);
        return combinations;
    }

    public void backtrack(List<String> combinations, String current, int open, int close, int max) {
        if (current.length() == max * 2) {
            combinations.add(current);
            return;
        }

        if (open < max)
            backtrack(combinations, current + "(", open + 1, close, max);
        if (close < open)
            backtrack(combinations, current + ")", open, close + 1, max);
    }
}

