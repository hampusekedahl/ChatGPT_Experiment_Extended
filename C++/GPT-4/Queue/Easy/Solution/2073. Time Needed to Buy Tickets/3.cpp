#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size(), time = 0;
        priority_queue<pair<int, pair<int, int>>> pq; // tickets, time, index

        // Initialize the queue with tickets, time, index
        for(int i = 0; i < n; ++i) {
            pq.push({tickets[i], {n-i, i}});
        }

        while(true) {
            auto top = pq.top();
            pq.pop();
            time++;
            
            // If it's the kth person and no tickets left, break
            if(top.second.second == k && top.first == 1)
                break;
            
            // If there're still tickets left, push the person back to the queue
            if(top.first > 1)
                pq.push({top.first - 1, {top.second.first, top.second.second}});
        }

        return time;
    }
};
