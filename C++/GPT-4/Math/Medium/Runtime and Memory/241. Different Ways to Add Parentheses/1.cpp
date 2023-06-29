#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<string, vector<int>> memo;
public:
    vector<int> diffWaysToCompute(string expression) {
        // Return if the result has been computed before
        if (memo.count(expression)) {
            return memo[expression];
        }

        vector<int> output;
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (ispunct(c))  // operator found
                for (int a : diffWaysToCompute(expression.substr(0, i)))  // left part
                    for (int b : diffWaysToCompute(expression.substr(i + 1)))  // right part
                        output.push_back(c == '+' ? a + b : c == '-' ? a - b : a * b);
        }
        // if output is empty, the expression is a number
        if (output.empty()) {
            output.push_back(stoi(expression));
        }
        // save the result in memo
        memo[expression] = output;
        return output;
    }
};
