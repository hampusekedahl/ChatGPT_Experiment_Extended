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
                }

                if (c == ')') {
                    int sum = 0;
                    while (ops.top() != '(') {
                        sum += nums.top();
                        nums.pop();
                    }
                    ops.pop(); // Remove the '('
                    num = sum;
                } else {
                    op = c;
                    num = 0;
                }
            }
        }

        int sum = 0;
        while (!nums.empty()) {
            sum += nums.top();
            nums.pop();
        }

        return sum;
    }
};
