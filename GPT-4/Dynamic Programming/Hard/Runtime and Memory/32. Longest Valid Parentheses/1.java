import java.util.Stack;

class Solution {
    public int longestValidParentheses(String s) {
        int maxLength = 0, lastInvalidIndex = -1;
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                if (stack.isEmpty()) {
                    lastInvalidIndex = i;
                } else {
                    stack.pop();
                    if (stack.isEmpty()) {
                        maxLength = Math.max(maxLength, i - lastInvalidIndex);
                    } else {
                        maxLength = Math.max(maxLength, i - stack.peek());
                    }
                }
            }
        }

        return maxLength;
    }
}

