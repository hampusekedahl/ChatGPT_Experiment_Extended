#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (size_t i = 1; i < intervals.size(); i++) {
            // If current interval does not overlap with the last merged interval, add to merged list
            if (merged.back()[1] < intervals[i][0]) {
                merged.push_back(intervals[i]);
            } else {
                // Otherwise, there is an overlap, so we merge the current and last interval
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            }
        }

        return merged;
    }
};
