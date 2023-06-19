#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int total_len = target.length();
        int stamp_len = stamp.length();
        vector<int> ans;
        vector<bool> visited(total_len, false);
        int done = 0;

        while (done < total_len) {
            bool found = false;
            for (int i = 0; i <= total_len - stamp_len; i++) {
                if (!visited[i] && can_stamp(stamp, target, i)) {
                    visited[i] = true;
                    ans.push_back(i);

                    for (int j = i; j < i + stamp_len; j++) {
                        if (target[j] != '?') {
                            target[j] = '?';
                            done++;
                        }
                    }

                    found = true;
                }
            }

            if (!found) return vector<int>();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    bool can_stamp(const string& stamp, const string& target, int idx) {
        for (int i = 0; i < stamp.size(); i++) {
            if (target[idx + i] != '?' && target[idx + i] != stamp[i]) {
                return false;
            }
        }
        return true;
    }
};
