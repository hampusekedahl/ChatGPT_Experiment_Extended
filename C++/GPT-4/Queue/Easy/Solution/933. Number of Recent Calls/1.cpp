#include <deque>

class RecentCounter {
public:
    std::deque<int> requests;

    RecentCounter() {
        
    }
    
    int ping(int t) {
        // Add the new request at time t.
        requests.push_back(t);

        // Remove requests that happened before the time range [t - 3000, t].
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop_front();
        }

        // Return the number of requests within the range [t - 3000, t].
        return requests.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
