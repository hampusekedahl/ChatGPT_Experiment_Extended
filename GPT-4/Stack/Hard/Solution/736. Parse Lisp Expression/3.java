import java.util.*;

class Solution {
    int i, n;
    String s;
    public int evaluate(String expression) {
        i = 0;
        s = expression;
        n = s.length();
        return eval(new HashMap<>());
    }

    private int eval(HashMap<String, Integer> map) {
        char c = s.charAt(i);
        if (c == '(') {
            i++; // Skip '('
            String str = parse();
            char op = str.charAt(0);
            int val;
            if (op == 'a' || op == 'm') {
                int v1 = eval(map), v2 = eval(map);
                val = op == 'a' ? v1 + v2 : v1 * v2;
            } else {
                HashMap<String, Integer> temp = new HashMap<>(map);
                while (s.charAt(i) != ')') {
                    String var = parse();
                    if (s.charAt(i) == ')') {
                        val = map.get(var);
                        break;
                    }
                    int varValue = eval(temp);
                    temp.put(var, varValue);
                }
                i++; // Skip ')'
                return val;
            }
            i++; // Skip ')'
            return val;
        } else if (c >= '0' && c <= '9' || c == '-') {
            boolean isNegative = c == '-';
            if (isNegative) i++;
            int val = parseNum();
            return isNegative ? -val : val;
        } else {
            String str = parse();
            return map.get(str);
        }
    }

    private String parse() {
        skipSpaces();
        int j = i;
        while (j < n && s.charAt(j) != ' ' && s.charAt(j) != ')') j++;
        String token = s.substring(i, j);
        i = j;
        return token;
    }

    private int parseNum() {
        skipSpaces();
        int j = i;
        while (j < n && Character.isDigit(s.charAt(j))) j++;
        int val = Integer.parseInt(s.substring(i, j));
        i = j;
        return val;
    }

    private void skipSpaces() {
        while (i < n && s.charAt(i) == ' ') i++;
    }
}

