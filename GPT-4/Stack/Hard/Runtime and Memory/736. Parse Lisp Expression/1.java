class Solution {
    int i, n;
    String s;
    Map<String, Integer> map = new HashMap<>();

    public int evaluate(String expression) {
        i = 0;
        n = expression.length();
        s = expression;
        map.clear();
        return eval();
    }

    int eval() {
        char ch = s.charAt(i++);
        if (ch == '(') {
            ch = s.charAt(i++);
            if (ch == 'a') {  // add
                i += 3;
                int a = eval();
                i++;  // skip ' '
                int b = eval();
                i++;  // skip ')'
                return a + b;
            } else if (ch == 'm') {  // mult
                i += 4;
                int a = eval();
                i++;  // skip ' '
                int b = eval();
                i++;  // skip ')'
                return a * b;
            } else {  // let
                i += 3;
                Map<String, Integer> old = new HashMap<>(map);
                while (s.charAt(i) != ')') {
                    if (s.charAt(i) != ' ') {
                        String var = parseVar();
                        i++;  // skip ' '
                        if (s.charAt(i) == '(' || Character.isDigit(s.charAt(i)) || s.charAt(i) == '-') {
                            map.put(var, eval());
                            i++;  // skip ' ' or ')'
                        } else {
                            map.put(var, map.get(parseVar()));
                            i++;  // skip ' ' or ')'
                        }
                    } else {
                        i++;  // skip ' '
                    }
                }
                int val = map.get(parseVar());
                map = old;
                return val;
            }
        } else {
            i--;  // roll back
            return Character.isDigit(ch) || ch == '-' ? parseNum() : map.get(parseVar());
        }
    }

    String parseVar() {
        int j = i;
        while (s.charAt(i) != ' ' && s.charAt(i) != ')') {
            i++;
        }
        return s.substring(j, i);
    }

    int parseNum() {
        int j = i;
        while (i < n && (s.charAt(i) != ' ' && s.charAt(i) != ')')) {
            i++;
        }
        return Integer.parseInt(s.substring(j, i));
    }
}

