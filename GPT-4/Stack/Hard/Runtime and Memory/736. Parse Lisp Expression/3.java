import java.util.*;

class Solution {
    public int evaluate(String expression) {
        return eval(expression, new ArrayDeque<>());
    }

    private int eval(String exp, Deque<Map<String, Integer>> scope) {
        if (Character.isDigit(exp.charAt(0)) || exp.charAt(0) == '-')
            return Integer.parseInt(exp);
        else if (!exp.startsWith("(")) {
            Map<String, Integer> currentScope = scope.peek();
            if (currentScope.containsKey(exp)) {
                return currentScope.get(exp);
            } else {
                return 0;  // Return a default value for undefined variables
            }
        }

        // Create a new scope
        Map<String, Integer> map = new HashMap<>();
        scope.push(map);
        
        // To handle variable and function expressions separately
        String[] tokens;
        if (exp.charAt(1) == 'l') {  // let expression
            tokens = exp.substring(5, exp.length() - 1).split(" ");
        } else {  // add or mult expression
            tokens = exp.substring(6, exp.length() - 1).split(" ");
        }

        int res = 0;
        if (exp.charAt(1) == 'a')  // add expression
            res = eval(tokens[0], scope) + eval(tokens[1], scope);
        else if (exp.charAt(1) == 'm')  // mult expression
            res = eval(tokens[0], scope) * eval(tokens[1], scope);
        else {  // let expression
            for (int i = 0; i < tokens.length - 2; i += 2)
                map.put(tokens[i], eval(tokens[i + 1], scope));
            res = eval(tokens[tokens.length - 1], scope);
        }

        // Remove the scope
        scope.pop();
        return res;
    }
}

