#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missingNumber = nums.size(); // Initialize the missing number as n

        // Iterate through the array, XOR the index with the element and the missingNumber
        for (int i = 0; i < nums.size(); ++i) {
            missingNumber ^= i ^ nums[i];
        }

        return missingNumber;
    }
};
