#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        priority_queue<pair<int, int>> pq;
        int n = tickets.size();

        for(int i = 0; i < n; i++)
            pq.push({tickets[i], -i});
        
        int time = 0;
        while(true){
            int ticket = pq.top().first;
            int person = -pq.top().second;
            pq.pop();
            
            // if it's the kth person and no tickets left, break
            if(person == k && ticket == 1)
                break;
            
            // increment time
            time++;
            if(ticket > 1)
                pq.push({ticket - 1, -person});
        }

        return time + 1;
    }
};
