import java.util.*;

class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> ways = new ArrayList<>();
        
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                String part1 = input.substring(0, i);
                String part2 = input.substring(i + 1);
                List<Integer> part1Ways = diffWaysToCompute(part1);
                List<Integer> part2Ways = diffWaysToCompute(part2);
                for (int p1 : part1Ways) {
                    for (int p2 : part2Ways) {
                        switch (c) {
                            case '+':
                                ways.add(p1 + p2);
                                break;
                            case '-':
                                ways.add(p1 - p2);
                                break;
                            case '*':
                                ways.add(p1 * p2);
                                break;
                        }
                    }
                }
            }
        }
        
        if (ways.isEmpty()) {
            ways.add(Integer.parseInt(input));
        }
        return ways;
    }
}

