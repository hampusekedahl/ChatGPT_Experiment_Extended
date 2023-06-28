#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        int num = 0;
        int result = 0;
        int sign = 1;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                nums.push(result);
                nums.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                num = 0;

                result *= nums.top(); // multiply by the sign before the '('
                nums.pop();
                result += nums.top(); // add the result before the '('
                nums.pop();
            }
        }
        if (num != 0) {
            result += sign * num;
        }
        return result;
    }
};
