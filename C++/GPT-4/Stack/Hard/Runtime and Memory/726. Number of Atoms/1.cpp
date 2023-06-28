#include <string>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stk;
        stk.push(map<string, int>());
        int n = formula.size();

        for (int i = 0; i < n;) {
            if (formula[i] == '(') {
                stk.push(map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                i++;
                int start = i;
                int count = 1;
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                if (i > start) {
                    count = stoi(formula.substr(start, i - start));
                }
                map<string, int> temp = stk.top();
                stk.pop();
                for (const auto& atom : temp) {
                    stk.top()[atom.first] += atom.second * count;
                }
            } else {
                int start = i++;
                while (i < n && islower(formula[i])) {
                    i++;
                }
                string atom = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                int count = i > start ? stoi(formula.substr(start, i - start)) : 1;
                stk.top()[atom] += count;
            }
        }

        stringstream ss;
        map<string, int> atomsCount = stk.top();
        for (const auto& atom : atomsCount) {
            ss << atom.first;
            if (atom.second > 1) {
                ss << atom.second;
            }
        }

        return ss.str();
    }
};
