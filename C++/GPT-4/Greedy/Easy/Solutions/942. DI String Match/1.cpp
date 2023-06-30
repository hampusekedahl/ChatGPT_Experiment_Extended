#include<vector>
#include<string>

class Solution {
public:
    std::vector<int> diStringMatch(std::string s) {
        int left = 0;
        int right = s.size();
        std::vector<int> result;

        for (char c : s) {
            if (c == 'I') {
                result.push_back(left++);
            } else {
                result.push_back(right--);
            }
        }
        
        // push the last element
        result.push_back(left);
        return result;
    }
};
