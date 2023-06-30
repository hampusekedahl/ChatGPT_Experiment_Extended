#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size(), time = 0;
        queue<pair<int, int>> q; // store the original order
        priority_queue<pair<int, int>> pq; // store the tickets and index

        // Initialize the queues
        for(int i = 0; i < n; ++i) {
            q.push({tickets[i], i});
            pq.push({tickets[i], i});
        }

        while(true){
            auto top = pq.top();
            // Sell tickets in the original order
            while(top.first != q.front().first || top.second != q.front().second){
                auto cur = q.front();
                q.pop();
                q.push({cur.first, cur.second});
            }
            
            // Sell one ticket
            q.pop();
            pq.pop();
            time++;

            // If it's the kth person and no tickets left, break
            if(top.second == k && top.first == 1)
                break;
            
            // If there're still tickets left, push the person back to the queue
            if(top.first > 1)
                pq.push({top.first - 1, top.second});
        }

        return time;
    }
};
