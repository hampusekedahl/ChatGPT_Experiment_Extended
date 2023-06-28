#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(std::to_string(num));
        }

        std::sort(strNums.begin(), strNums.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });

        if (strNums[0] == "0") {
            return "0";
        }

        string result;
        for (const string &str : strNums) {
            result += str;
        }

        return result;
    }
};
