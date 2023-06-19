#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        struct Compare {
            bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
                return a.first > b.first;
            }
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> min_heap;
        int max_val = numeric_limits<int>::min();
        int min_range = numeric_limits<int>::max();
        int start = -1, end = -1;

        for (int i = 0; i < nums.size(); ++i) {
            min_heap.push({nums[i][0], i});
            max_val = max(max_val, nums[i][0]);
        }

        vector<int> indices(nums.size(), 0);

        while (!min_heap.empty()) {
            auto [val, list_idx] = min_heap.top();
            min_heap.pop();

            if (max_val - val < min_range) {
                min_range = max_val - val;
                start = val;
                end = max_val;
            }

            if (++indices[list_idx] < nums[list_idx].size()) {
                int next_val = nums[list_idx][indices[list_idx]];
                min_heap.push({next_val, list_idx});
                max_val = max(max_val, next_val);
            } else {
                break;
            }
        }

        return {start, end};
    }
};
