#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        std::vector<std::string> str_nums;
        for (int num : nums) {
            str_nums.push_back(std::to_string(num));
        }

        auto compare = [](const std::string& a, const std::string& b) {
            return a + b > b + a;
        };

        std::sort(str_nums.begin(), str_nums.end(), compare);

        std::string result;
        for (const std::string& str_num : str_nums) {
            result += str_num;
        }

        // Remove leading zeros
        while (result.size() > 1 && result[0] == '0') {
            result.erase(result.begin());
        }

        return result;
    }
};
