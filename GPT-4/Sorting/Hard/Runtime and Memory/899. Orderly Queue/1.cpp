#include <string>
#include <algorithm>

using std::string;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string best = s;
            for (int i = 1; i < s.length(); ++i) {
                string candidate = s.substr(i) + s.substr(0, i);
                if (candidate < best) {
                    best = candidate;
                }
            }
            return best;
        } else {
            std::sort(s.begin(), s.end());
            return s;
        }
    }
};
