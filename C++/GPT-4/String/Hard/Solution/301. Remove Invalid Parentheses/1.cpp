#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        std::unordered_set<std::string> result;
        int leftToRemove = 0, rightToRemove = 0;

        // Count the number of invalid parentheses
        for (char c : s) {
            if (c == '(') {
                leftToRemove++;
            } else if (c == ')') {
                if (leftToRemove > 0) {
                    leftToRemove--;
                } else {
                    rightToRemove++;
                }
            }
        }

        // Helper function to perform backtracking
        std::function<void(int, int, int, std::string)> backtrack = [&](int index, int leftCount, int rightCount, std::string current) {
            if (index == s.size()) {
                if (leftToRemove == 0 && rightToRemove == 0 && leftCount == rightCount) {
                    result.insert(current);
                }
                return;
            }

            if (s[index] == '(') {
                // Remove this parenthesis
                if (leftToRemove > 0) {
                    backtrack(index + 1, leftCount, rightCount, current);
                }

                // Keep this parenthesis
                backtrack(index + 1, leftCount + 1, rightCount, current + s[index]);
                leftToRemove--;

            } else if (s[index] == ')') {
                // Remove this parenthesis
                if (rightToRemove > 0) {
                    backtrack(index + 1, leftCount, rightCount, current);
                }

                // Keep this parenthesis
                if (rightCount < leftCount) {
                    backtrack(index + 1, leftCount, rightCount + 1, current + s[index]);
                }
                rightToRemove--;

            } else {
                // Add character to the current string
                backtrack(index + 1, leftCount, rightCount, current + s[index]);
            }
        };

        backtrack(0, 0, 0, "");
        return std::vector<std::string>(result.begin(), result.end());
    }
};
