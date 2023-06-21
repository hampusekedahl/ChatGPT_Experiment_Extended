import java.util.Stack;

class Solution {
    public String simplifyPath(String path) {
        Stack<String> stack = new Stack<>();
        String[] elements = path.split("/");

        for (String element : elements) {
            if (element.equals("..")) {
                if (!stack.isEmpty()) {
                    stack.pop();
                }
            } else if (!element.equals("") && !element.equals(".")) {
                stack.push(element);
            }
        }

        return "/" + String.join("/", stack);
    }
}

