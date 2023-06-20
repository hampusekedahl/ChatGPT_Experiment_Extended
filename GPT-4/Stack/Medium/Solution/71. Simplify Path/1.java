import java.util.*;

class Solution {
    public String simplifyPath(String path) {
        Deque<String> stack = new LinkedList<>();
        for(String part : path.split("/")) {
            if(part.equals("..") && !stack.isEmpty()) {
                stack.pop();
            } else if(!part.isEmpty() && !part.equals(".") && !part.equals("..")) {
                stack.push(part);
            }
        }
        
        StringBuilder result = new StringBuilder();
        for(String dir : stack) {
            result.insert(0, dir).insert(0, "/");
        }
        
        return result.length() > 0 ? result.toString() : "/";
    }
}

