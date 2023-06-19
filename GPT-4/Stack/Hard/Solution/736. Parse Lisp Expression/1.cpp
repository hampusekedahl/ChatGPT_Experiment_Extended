#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

class Solution {
public:
    int evaluate(std::string expression) {
        std::stack<char> st;
        std::vector<std::unordered_map<std::string, int>> scope;

        for (int i = expression.size() - 1; i >= 0; --i) {
            char c = expression[i];
            if (c == ')') {
                st.push(c);
            } else if (c == '(' || c == ' ') {
                continue;
            } else {
                std::string token;
                while (i >= 0 && expression[i] != ' ' && expression[i] != '(') {
                    token.push_back(expression[i--]);
                }
                st.push(eval(token, scope));
            }
        }

        return st.top();
    }

    int eval(std::string token, std::vector<std::unordered_map<std::string, int>>& scope) {
        if (token == "let") {
            scope.push_back({});
            while (true) {
                std::string var = eval(st.top(), scope);
                st.pop();
                if (st.top() == "let") {
                    scope.pop_back();
                    return stoi(var);
                }
                int value = eval(st.top(), scope);
                st.pop();
                scope.back()[var] = value;
            }
        } else if (token == "add") {
            int e1 = eval(st.top(), scope);
            st.pop();
            int e2 = eval(st.top(), scope);
            st.pop();
            return e1 + e2;
        } else if (token == "mult") {
            int e1 = eval(st.top(), scope);
            st.pop();
            int e2 = eval(st.top(), scope);
            st.pop();
            return e1 * e2;
        } else {
            for (int i = scope.size() - 1; i >= 0; --i) {
                if (scope[i].count(token)) {
                    return scope[i][token];
                }
            }
            return stoi(token);
        }
    }
};
