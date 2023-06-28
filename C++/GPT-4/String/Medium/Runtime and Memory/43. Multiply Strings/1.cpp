#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();
        vector<int> result(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int p1 = i + j;
                int p2 = i + j + 1;
                int sum = (num1[i] - '0') * (num2[j] - '0') + result[p2];

                result[p1] += sum / 10;
                result[p2] = sum % 10;
            }
        }

        string product;
        for (int num : result) {
            if (!(product.empty() && num == 0)) {
                product += std::to_string(num);
            }
        }

        return product.empty() ? "0" : product;
    }
};
