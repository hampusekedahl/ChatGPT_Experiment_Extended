#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Compare {
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> pq;
        int maxVal = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }

        int range = INT_MAX;
        int start = -1, end = -1;

        while (pq.size() == nums.size()) {
            auto current = pq.top();
            pq.pop();

            int currentVal = current.first;
            int listIdx = current.second.first;
            int elementIdx = current.second.second;

            if (maxVal - currentVal < range) {
                range = maxVal - currentVal;
                start = currentVal;
                end = maxVal;
            }

            if (elementIdx + 1 < nums[listIdx].size()) {
                int nextVal = nums[listIdx][elementIdx + 1];
                pq.push({nextVal, {listIdx, elementIdx + 1}});
                maxVal = max(maxVal, nextVal);
            }
        }

        return {start, end};
    }
};