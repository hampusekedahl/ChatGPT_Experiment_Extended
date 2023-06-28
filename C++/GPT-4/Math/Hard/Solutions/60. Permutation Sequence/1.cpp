#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> nums(n);
        int fact = 1;
        
        for (int i = 1; i <= n; i++) {
            fact *= i;
            nums[i - 1] = i;
        }
        
        k--; // To convert k to 0-based index
        for (int i = 0; i < n; i++) {
            fact /= (n - i);
            int index = k / fact;
            res.push_back(nums[index] + '0');
            nums.erase(nums.begin() + index);
            k %= fact;
        }
        
        return res;
    }
};
