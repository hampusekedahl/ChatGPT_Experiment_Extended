#include <queue>
#include <deque>

class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        std::priority_queue<std::pair<int, int>> pq;
        std::deque<std::pair<int, int>> dq;
        int n = tickets.size();
        for (int i = 0; i < n; ++i) {
            pq.push({tickets[i], i});
            dq.push_back({tickets[i], i});
        }
        
        int time = 0;
        while (!pq.empty()) {
            std::pair<int, int> top = pq.top();
            std::pair<int, int> front = dq.front();
            dq.pop_front();

            if (top.second != front.second || front.second == k) {
                // either the person at the front of the queue is the one who has most tickets
                // or they are the person we are tracking, then they can buy a ticket
                time++;
                front.first--;
                if (front.second == k && front.first == 0) {
                    break;
                }
                if (top.second == front.second) {
                    pq.pop();
                }
            }
            // if they still need to buy tickets, they go to the back of the queue
            if (front.first > 0) {
                dq.push_back(front);
                if (top.second == front.second) {
                    pq.push(front);
                }
            }
        }

        return time;
    }
};
