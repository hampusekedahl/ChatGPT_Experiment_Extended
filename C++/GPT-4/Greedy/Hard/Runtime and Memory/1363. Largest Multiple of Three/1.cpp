#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int freq[10] = {0};
        int sum = 0;
        
        for(int digit: digits) {
            freq[digit]++;
            sum += digit;
        }

        if(sum % 3 == 1) {
            if(!removeDigit(freq, 1)) {
                removeDigit(freq, 2);
                removeDigit(freq, 2);
            }
        }
        else if(sum % 3 == 2) {
            if(!removeDigit(freq, 2)) {
                removeDigit(freq, 1);
                removeDigit(freq, 1);
            }
        }

        string result = "";
        for(int i = 9; i >= 0; --i) {
            while(freq[i] > 0) {
                result += to_string(i);
                freq[i]--;
            }
        }

        // If the result starts with '0', the answer is either '0' or an empty string
        if (!result.empty() && result[0] == '0') {
            return "0";
        }
        
        return result;
    }

private:
    bool removeDigit(int freq[], int rem) {
        for(int i = rem; i <= 9; i += 3) {
            if(freq[i] > 0) {
                freq[i]--;
                return true;
            }
        }
        return false;
    }
};
