import java.util.*;

class Solution {
    public int calculate(String s) {
        int len;
        if(s==null || (len = s.length())==0) return 0;
        Stack<Integer> stack = new Stack<>();
        int num = 0;
        int result = 0;
        int sign = 1;
        for(int i=0;i<len;i++){
            char c = s.charAt(i);
            if(Character.isDigit(c)){
                num = num*10+c-'0';
            }else if(c=='+'){
                result += sign*num;
                sign = 1;
                num = 0;
            }else if(c=='-'){
                result += sign*num;
                sign = -1;
                num = 0;
            }else if(c=='('){
                //we push the result first, then sign;
                stack.push(result);
                stack.push(sign);
                //reset the sign and result for the value in the parenthesis
                sign = 1;   
                result = 0;
            }else if(c==')'){
                result += sign*num;
                num = 0;
                //stack.pop() is the sign before the parenthesis
                result *= stack.pop();    //stack.pop() is the result calculated before the parenthesis
                result += stack.pop();
            }
        }
        if(num!=0) result += sign*num;
        return result;
    }
}
