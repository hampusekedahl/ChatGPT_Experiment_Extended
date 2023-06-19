#include <string>
#include <map>
#include <stack>
#include <sstream>
#include <iostream>

class Solution {
public:
    std::string countOfAtoms(std::string formula) {
        int n = formula.size();
        std::stack<std::map<std::string, int>> st;
        st.push(std::map<std::string, int>());
        
        for (int i = 0; i < n;) {
            if (formula[i] == '(') {
                st.push(std::map<std::string, int>());
                i++;
            } else if (formula[i] == ')') {
                int j = i + 1;
                int cnt = 0;
                while (j < n && isdigit(formula[j])) {
                    cnt = cnt * 10 + formula[j++] - '0';
                }
                if (cnt == 0) cnt = 1;
                auto top = st.top();
                st.pop();
                for (const auto &kv : top) {
                    st.top()[kv.first] += kv.second * cnt;
                }
                i = j;
            } else {
                int j = i + 1;
                while (j < n && islower(formula[j])) {
                    j++;
                }
                std::string atom = formula.substr(i, j - i);
                i = j;
                int cnt = 0;
                while (i < n && isdigit(formula[i])) {
                    cnt = cnt * 10 + formula[i++] - '0';
                }
                if (cnt == 0) cnt = 1;
                st.top()[atom] += cnt;
            }
        }
        
        std::stringstream ss;
        for (const auto &kv : st.top()) {
            ss << kv.first;
            if (kv.second > 1) ss << kv.second;
        }
        return ss.str();
    }
};

int main() {
    Solution solution;

    std::string formula1 = "H2O";
    std::string formula2 = "Mg(OH)2";
    std::string formula3 = "K4(ON(SO3)2)2";

    std::cout << solution.countOfAtoms(formula1) << std::endl; // Output: "H2O"
    std::cout << solution.countOfAtoms(formula2) << std::endl; // Output: "H2MgO2"
    std::cout << solution.countOfAtoms(formula3) << std::endl; // Output: "K4N2O14S4"

    return 0;
}
