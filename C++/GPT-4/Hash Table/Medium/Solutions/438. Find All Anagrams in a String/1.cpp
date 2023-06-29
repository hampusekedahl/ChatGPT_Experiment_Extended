#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.size() < p.size()) 
            return ans;

        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);

        // count occurrence of each character in the first 'p' characters of 's' and 'p'
        for(int i = 0; i < p.size(); i++) {
            sCount[s[i] - 'a']++;
            pCount[p[i] - 'a']++;
        }
        
        if(pCount == sCount) 
            ans.push_back(0);
        
        // slide over the rest of 's'
        for(int i = p.size(); i < s.size(); i++) {
            sCount[s[i] - 'a']++;
            sCount[s[i - p.size()] - 'a']--;
            
            if(pCount == sCount) 
                ans.push_back(i - p.size() + 1);
        }

        return ans;
    }
};
