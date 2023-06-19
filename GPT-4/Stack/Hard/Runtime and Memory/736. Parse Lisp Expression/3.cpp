#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    int evaluate(string expression) {
        unordered_map<string, int> scope;
        return evaluate(expression, scope);
    }
    
private:
    int evaluate(const string& expression, unordered_map<string, int>& scope) {
        if (isdigit(expression[0]) || expression[0] == '-')
            return stoi(expression);
        
        if (isalpha(expression[0]))
            return scope[expression];
        
        int i = 1, j;
        string cmd = parse(expression, i);
        if (cmd == "add") {
            int left = evaluate(parse(expression, i), scope);
            int right = evaluate(parse(expression, i), scope);
            return left + right;
        } else if (cmd == "mult") {
            int left = evaluate(parse(expression, i), scope);
            int right = evaluate(parse(expression, i), scope);
            return left * right;
        } else { // let
            unordered_map<string, int> newScope = scope;
            while (true) {
                string var = parse(expression, i);
                if (i >= expression.size())
                    return evaluate(var, newScope);
                string value = parse(expression, i);
                newScope[var] = evaluate(value, newScope);
            }
        }
    }
    
    string parse(const string& expression, int& i) {
        if (i >= expression.size()) return "";
        
        int j = i;
        while (i < expression.size() && expression[i] != ' ' && expression[i] != ')') i++;
        string res = expression.substr(j, i - j);
        while (i < expression.size() && (expression[i] == ' ' || expression[i] == ')')) i++;
        return res;
    }
};
