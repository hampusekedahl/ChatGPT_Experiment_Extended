import java.util.*;

class Solution {
    int p = 0;
    String s;

    public int evaluate(String expression) {
        s = expression;
        return parse(new HashMap<>());
    }

    private int parse(Map<String, Integer> map) {
        char c = s.charAt(p++);
        if (c == '(') {
            if (s.startsWith("let ", p)) {
                p += 4;
                Map<String, Integer> next = new HashMap<>(map);
                while (s.charAt(p) != ')') {
                    String var = parseVar();
                    if (s.charAt(p) == ' ') {
                        p++; // skip ' '
                        next.put(var, parse(next));
                    } else { // ')'
                        int result = map.containsKey(var) ? map.get(var) : parse(next);
                        p++; // skip ')'
                        return result;
                    }
                }
                p++; // skip ')'
                return 0; // should never reach here
            } else if (s.startsWith("add ", p)) {
                p += 4;
                int first = parse(map), second = parse(map);
                p++; // skip ')'
                return first + second;
            } else { // "mult"
                p += 5;
                int first = parse(map), second = parse(map);
                p++; // skip ')'
                return first * second;
            }
        } else if (Character.isDigit(c) || c == '-') {
            boolean negative = c == '-';
            int num = negative ? 0 : c - '0';
            while (p < s.length() && Character.isDigit(s.charAt(p)))
                num = num * 10 + (s.charAt(p++) - '0');
            return negative ? -num : num;
        } else {
            String var = parseVar();
            return map.get(var);
        }
    }

    private String parseVar() {
        int start = p;
        while (p < s.length() && s.charAt(p) != ' ' && s.charAt(p) != ')')
            p++;
        return s.substring(start, p);
    }
}

