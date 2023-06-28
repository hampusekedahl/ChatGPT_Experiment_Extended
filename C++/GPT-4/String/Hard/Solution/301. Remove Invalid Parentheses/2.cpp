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
        std::function<void(int, int, int, std::string, int, int)> backtrack = [&](int index, int leftCount, int rightCount, std::string current, int leftRemoved, int rightRemoved) {
            if (index == s.size()) {
                if (leftRemoved == leftToRemove && rightRemoved == rightToRemove && leftCount == rightCount) {
                    result.insert(current);
                }
                return;
            }

            if (s[index] == '(') {
                // Remove this parenthesis
                if (leftRemoved < leftToRemove) {
                    backtrack(index + 1, leftCount, rightCount, current, leftRemoved + 1, rightRemoved);
                }

                // Keep this parenthesis
                backtrack(index + 1, leftCount + 1, rightCount, current + s[index], leftRemoved, rightRemoved);

            } else if (s[index] == ')') {
                // Remove this parenthesis
                if (rightRemoved < rightToRemove) {
                    backtrack(index + 1, leftCount, rightCount, current, leftRemoved, rightRemoved + 1);
                }

                // Keep this parenthesis
                if (rightCount < leftCount) {
                    backtrack(index + 1, leftCount, rightCount + 1, current + s[index], leftRemoved, rightRemoved);
                }

            } else {
                // Add character to the current string
                backtrack(index + 1, leftCount, rightCount, current + s[index], leftRemoved, rightRemoved);
            }
        };

        backtrack(0, 0, 0, "", 0, 0);
        return std::vector<std::string>(result.begin(), result.end());
    }
};
