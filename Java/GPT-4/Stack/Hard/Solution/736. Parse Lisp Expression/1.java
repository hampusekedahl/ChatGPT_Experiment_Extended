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
        int val = 0;
        if (c == '(') {
            String str = parse();
            char op = str.charAt(0);
            if (op == 'a' || op == 'm') {
                int v1 = eval(map), v2 = eval(map);
                val = op == 'a' ? v1 + v2 : v1 * v2;
            } else {
                HashMap<String, Integer> temp = new HashMap<>(map);
                for (; s.charAt(i) != ')';) {
                    String v = parse();
                    if (s.charAt(i) == ')') {
                        val = temp.get(v);
                        break;
                    }
                    int vv = eval(temp);
                    temp.put(v, vv);
                }
            }
        } else if (c >= '0' && c <= '9' || c == '-') {
            boolean neg = c == '-';
            if (neg) {
                i++;
            }
            val = parseNum();
            if (neg) {
                val = -val;
            }
        } else {
            String str = parse();
            val = map.get(str);
        }
        i++;
        return val;
    }

    private String parse() {
        int j = s.indexOf(' ', i);
        int k = s.indexOf(')', i);
        int end = (j == -1 || k == -1) ? Math.max(j, k) : Math.min(j, k);
        String str = end == -1 ? s.substring(i) : s.substring(i, end);
        i = end;
        return str;
    }

    private int parseNum() {
        int j = s.indexOf(' ', i);
        int k = s.indexOf(')', i);
        int end = (j == -1 || k == -1) ? Math.max(j, k) : Math.min(j, k);
        int val = Integer.parseInt(s.substring(i, end));
        i = end;
        return val;
    }
}
