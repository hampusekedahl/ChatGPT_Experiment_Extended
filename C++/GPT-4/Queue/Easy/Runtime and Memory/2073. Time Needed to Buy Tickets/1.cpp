#include <queue>
#include <vector>

class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        using pii = std::pair<int, int>; // pair of int
        auto cmp = [](const pii& left, const pii& right) { // custom compare function
            return (left.first < right.first) || (left.first == right.first && left.second > right.second);
        };
        std::priority_queue<pii, std::vector<pii>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < tickets.size(); ++i) {
            pq.push({tickets[i], i});
        }

        int time = 0;
        while (!pq.empty()) {
            pii person = pq.top();
            pq.pop();
            time++;
            if (person.second == k && person.first == 1) {
                break;
            }
            if (person.first > 1) {
                pq.push({person.first - 1, person.second});
            }
        }
        return time;
    }
};
