#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> ans;
        if (s.size() < p.size()) return ans;

        std::vector<int> sFreq(26, 0), pFreq(26, 0);
        for(int i = 0; i < p.size(); i++) {
            sFreq[s[i] - 'a']++;
            pFreq[p[i] - 'a']++;
        }
        
        if(sFreq == pFreq)
            ans.push_back(0);

        for(int i = p.size(); i < s.size(); i++) {
            sFreq[s[i] - 'a']++;
            sFreq[s[i - p.size()] - 'a']--;
            if(sFreq == pFreq)
                ans.push_back(i - p.size() + 1);
        }
        
        return ans;
    }
};
