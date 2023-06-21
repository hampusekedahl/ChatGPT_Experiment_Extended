import java.util.*;

class Solution {
    int i;

    public String countOfAtoms(String formula) {
        i = formula.length() - 1;
        Deque<Map<String, Integer>> stack = new ArrayDeque<>();
        stack.push(new TreeMap<>());

        while (i >= 0) {
            if (formula.charAt(i) == ')') {
                stack.push(new TreeMap<>());
                i--;
            } else if (formula.charAt(i) == '(') {
                Map<String, Integer> top = stack.pop();
                int num = parseNum(formula);
                for (String name : top.keySet()) {
                    stack.peek().put(name, stack.peek().getOrDefault(name, 0) + top.get(name) * num);
                }
                i--;
            } else {
                String name = parseName(formula);
                int num = parseNum(formula);
                stack.peek().put(name, stack.peek().getOrDefault(name, 0) + num);
            }
        }

        StringBuilder sb = new StringBuilder();
        for (String name : stack.peek().keySet()) {
            int num = stack.peek().get(name);
            sb.append(name);
            if (num > 1) sb.append(num);
        }
        return sb.toString();
    }

    private int parseNum(String formula) {
        int num = 0, start = i;
        while (i >= 0 && Character.isDigit(formula.charAt(i))) {
            num = num + (int) ((formula.charAt(i) - '0') * Math.pow(10, start - i));
            i--;
        }
        return num == 0 ? 1 : num;
    }

    private String parseName(String formula) {
        int start = i;
        i--;
        while (i >= 0 && Character.isLowerCase(formula.charAt(i))) {
            i--;
        }
        return formula.substring(i + 1, start + 1);
    }
}
