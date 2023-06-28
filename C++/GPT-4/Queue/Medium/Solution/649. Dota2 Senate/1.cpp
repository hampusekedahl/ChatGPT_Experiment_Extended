#include <string>
#include <queue>

class Solution {
public:
    std::string predictPartyVictory(std::string senate) {
        std::queue<int> radiant, dire;
        
        int n = senate.size();
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }
        
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front(), d = dire.front();
            radiant.pop();
            dire.pop();
            if (r < d)
                radiant.push(r + n);
            else
                dire.push(d + n);
        }
        
        return radiant.empty() ? "Dire" : "Radiant";
    }
};
