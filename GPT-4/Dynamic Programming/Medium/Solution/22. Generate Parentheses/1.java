import java.util.*;

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        generateParenthesis(result, "", 0, 0, n);
        return result;
    }
    
    private void generateParenthesis(List<String> result, String current, int open, int close, int max) {
        if (current.length() == max * 2) {
            result.add(current);
            return;
        }

        if (open < max)
            generateParenthesis(result, current + "(", open + 1, close, max);
        if (close < open)
            generateParenthesis(result, current + ")", open, close + 1, max);
    }
}

