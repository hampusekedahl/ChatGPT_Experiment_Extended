#include<queue>

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        int res = INT_MIN;
        for(auto& p : points) {
            while(!pq.empty() && p[0] - pq.top().second > k) {
                pq.pop();
            }
            if(!pq.empty()) {
                res = max(res, p[0] + p[1] + pq.top().first);
            }
            pq.push({p[1] - p[0], p[0]});
        }
        return res;
    }
};
