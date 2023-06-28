#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;

        int num = 0;
        char op = '+';

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (op == '+' || op == '-') {
                    nums.push(op == '+' ? num : -num);
                } else if (op == '(') {
                    nums.push(num);
                    ops.push(c);
                } else if (c == ')') {
                    while (ops.top() != '(') {
                        int top = nums.top();
                        nums.pop();
                        nums.top() += top;
                    }
                    ops.pop(); // Remove the '('
                }
                op = c;
                num = 0;
            }
        }

        while (!nums.empty()) {
            num += nums.top();
            nums.pop();
        }

        return num;
    }
};
