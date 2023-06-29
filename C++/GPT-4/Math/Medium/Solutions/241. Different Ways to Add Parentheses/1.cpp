#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> output;
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (ispunct(c))
                for (int a : diffWaysToCompute(expression.substr(0, i)))
                    for (int b : diffWaysToCompute(expression.substr(i + 1)))
                        output.push_back(c == '+' ? a + b : c == '-' ? a - b : a * b);
        }
        return output.size() ? output : vector<int>{stoi(expression)};
    }
};
