#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int left = 0;
        int right = s.size();
        vector<int> result(s.size() + 1);
        
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'I') {
                result[i] = left++;
            } else {
                result[i] = right--;
            }
        }
        
        result[s.size()] = left; // As left == right at the end, we can use either.
        return result;
    }
};
