import java.util.*;

class Solution {
    public int calPoints(String[] operations) {
        Stack<Integer> stack = new Stack<>();

        for (String operation : operations) {
            if (operation.equals("+")) {
                int top = stack.pop();
                int newtop = top + stack.peek();
                stack.push(top);
                stack.push(newtop);
            } else if (operation.equals("C")) {
                stack.pop();
            } else if (operation.equals("D")) {
                stack.push(2 * stack.peek());
            } else {
                stack.push(Integer.valueOf(operation));
            }
        }

        int total = 0;
        for(int score : stack) {
            total += score;
        }

        return total;
    }
}

