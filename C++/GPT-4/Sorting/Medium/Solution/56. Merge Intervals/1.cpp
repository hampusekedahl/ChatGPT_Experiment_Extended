#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        // Sort the intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        
        // Push the first interval to the merged vector
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            // If the current interval overlaps with the last interval in merged,
            // we update the end of the last interval in merged.
            if (intervals[i][0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                // Otherwise, we add this interval as a new non-overlapping interval.
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
