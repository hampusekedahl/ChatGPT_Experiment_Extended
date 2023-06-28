#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generateHelper(result, current, n, 0, 0);
        return result;
    }

    void generateHelper(vector<string>& result, string& current, int n, int open, int close) {
        if (current.length() == n * 2) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            current.push_back('(');
            generateHelper(result, current, n, open + 1, close);
            current.pop_back();
        }

        if (close < open) {
            current.push_back(')');
            generateHelper(result, current, n, open, close + 1);
            current.pop_back();
        }
    }
};
