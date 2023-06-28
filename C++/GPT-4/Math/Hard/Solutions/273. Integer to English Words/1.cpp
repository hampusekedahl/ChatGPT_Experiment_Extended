#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return helper(num).substr(1);
    }

private:
    const vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string helper(int num) {
        if (num == 0) {
            return "";
        } else if (num < 20) {
            return " " + below_20[num];
        } else if (num < 100) {
            return " " + tens[num / 10] + helper(num % 10);
        } else if (num < 1000) {
            return helper(num / 100) + " Hundred" + helper(num % 100);
        } else {
            for (int i = 0; i < thousands.size(); i++) {
                if (num < 1000 * (1000 ** i)) {
                    return helper(num / (1000 ** i)) + " " + thousands[i] + helper(num % (1000 ** i));
                }
            }
        }
        return "";
    }
};
