#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n + 1, 1);
        vector<int> numbers;
        string result = "";

        for (int i = 1; i <= n; ++i) {
            factorial[i] = i * factorial[i - 1];
            numbers.push_back(i);
        }

        k--; // Make k 0-indexed

        for (int i = n; i >= 1; --i) {
            int index = k / factorial[i - 1];
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= factorial[i - 1];
        }

        return result;
    }
};
