#include <string>
#include <vector>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        std::vector<int> result(n1 + n2, 0);

        // Perform multiplication
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int tempSum = result[i + j + 1] + product;

                result[i + j + 1] = tempSum % 10;
                result[i + j] += tempSum / 10;
            }
        }

        // Convert the result vector to string
        std::string resultStr;
        for (int num : result) {
            if (!(resultStr.empty() && num == 0)) {
                resultStr += std::to_string(num);
            }
        }

        return resultStr.empty() ? "0" : resultStr;
    }
};
