#include <vector>
#include <queue>

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // priority_queue to store pair<val, x>
        priority_queue<pair<int, int>> pq;

        int res = INT_MIN;
        for (auto& point : points) {
            // pop elements from pq if they are out of range
            while (!pq.empty() && point[0] - pq.top().second > k)
                pq.pop();
            
            // calculate the maximum value of the equation
            if (!pq.empty())
                res = max(res, point[0] + point[1] + pq.top().first);
            
            // push current point to pq
            pq.push({point[1] - point[0], point[0]});
        }
        return res;
    }
};
