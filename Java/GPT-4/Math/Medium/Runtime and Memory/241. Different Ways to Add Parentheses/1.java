import java.util.*;

class Solution {
    Map<String, List<Integer>> map = new HashMap<>();
    
    public List<Integer> diffWaysToCompute(String expression) {
        if (map.containsKey(expression)) return map.get(expression);
        
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                String leftPart = expression.substring(0, i);
                String rightPart = expression.substring(i+1);
                List<Integer> leftResults = diffWaysToCompute(leftPart);
                List<Integer> rightResults = diffWaysToCompute(rightPart);
                for (Integer left : leftResults) {
                    for (Integer right : rightResults) {
                        switch (c) {
                            case '+':
                                result.add(left + right);
                                break;
                            case '-':
                                result.add(left - right);
                                break;
                            case '*':
                                result.add(left * right);
                                break;
                        }
                    }
                }
            }
        }
        
        if (result.size() == 0) {
            result.add(Integer.valueOf(expression));
        }
        
        map.put(expression, result);
        return result;
    }
}

