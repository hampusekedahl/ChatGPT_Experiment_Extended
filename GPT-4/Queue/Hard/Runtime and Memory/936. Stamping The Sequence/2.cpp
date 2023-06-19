#include <vector>
#include <string>

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int stamp_len = stamp.size();
        int target_len = target.size();
        vector<int> result;
        
        auto can_stamp = [&](int index) {
            bool replaced = false;
            for (int i = 0; i < stamp_len; ++i) {
                if (target[index + i] != '?' && target[index + i] != stamp[i]) {
                    return false;
                }
                if (target[index + i] != '?') {
                    replaced = true;
                }
            }
            return replaced;
        };
        
        auto do_stamp = [&](int index) {
            for (int i = 0; i < stamp_len; ++i) {
                target[index + i] = '?';
            }
        };
        
        int turn_count = 0;
        bool stamped = true;
        
        while (stamped) {
            stamped = false;
            for (int i = 0; i <= target_len - stamp_len; ++i) {
                if (can_stamp(i)) {
                    do_stamp(i);
                    result.push_back(i);
                    stamped = true;
                }
            }
            ++turn_count;
            if (turn_count > 10 * target_len) break;
        }
        
        string empty_target(target_len, '?');
        if (target == empty_target) {
            reverse(result.begin(), result.end());
            return result;
        }
        
        return vector<int>();
    }
};
