#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int calPoints(std::vector<std::string>& operations) {
        std::stack<int> scores;

        for (const auto& op : operations) {
            if (op == "C") {
                scores.pop();
            } else if (op == "D") {
                scores.push(2 * scores.top());
            } else if (op == "+") {
                int top = scores.top();
                scores.pop();
                int new_top = top + scores.top();
                scores.push(top);
                scores.push(new_top);
            } else {
                scores.push(std::stoi(op));
            }
        }

        int sum = 0;
        while (!scores.empty()) {
            sum += scores.top();
            scores.pop();
        }

        return sum;
    }
};
