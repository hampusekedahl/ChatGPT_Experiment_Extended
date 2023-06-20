import java.util.*;

class Solution {
    int i;
    
    public int evaluate(String expression) {
        i = 0;
        return eval(expression, new HashMap<>());
    }

    private int eval(String expression, Map<String, Integer> parent) {
        char ch = expression.charAt(i);
        int value;
        if (ch == '(') {
            i++;  // Skip '('
            String op = parse(expression);
            if (op.equals("let")) {
                Map<String, Integer> scope = new HashMap<>(parent);
                String var = null;
                while (expression.charAt(i) != ')') {
                    if (expression.charAt(i) == ' ') {
                        i++;  // Skip ' '
                        continue;
                    }
                    if (var == null) {
                        var = parse(expression);
                    } else {
                        value = eval(expression, scope);
                        scope.put(var, value);
                        var = null;
                    }
                }
                i++;  // Skip ')'
                return value;
            } else {
                value = eval(expression, parent);
                if (op.equals("add")) {
                    value += eval(expression, parent);
                } else if (op.equals("mult")) {
                    value *= eval(expression, parent);
                }
                i++;  // Skip ')'
                return value;
            }
        } else if (Character.isDigit(ch) || ch == '-') {
            return parseNum(expression);
        } else {
            return parent.get(parse(expression));
        }
    }

    private String parse(String expression) {
        int start = i;
        while (i < expression.length() && expression.charAt(i) != ' ' && expression.charAt(i) != ')') {
            i++;
        }
        return expression.substring(start, i);
    }

    private int parseNum(String expression) {
        int start = i;
        while (i < expression.length() && (Character.isDigit(expression.charAt(i)) || expression.charAt(i) == '-')) {
            i++;
        }
        return Integer.parseInt(expression.substring(start, i));
    }
}

