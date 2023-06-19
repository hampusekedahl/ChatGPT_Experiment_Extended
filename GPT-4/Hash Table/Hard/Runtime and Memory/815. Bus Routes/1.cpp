#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, unordered_set<int>> stop_to_buses;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                stop_to_buses[stop].insert(i);
            }
        }

        queue<int> q;
        unordered_set<int> visited_stops;
        unordered_set<int> visited_buses;
        q.push(source);
        visited_stops.insert(source);
        int buses_taken = 0;

        while (!q.empty()) {
            int queue_size = q.size();
            buses_taken++;

            for (int i = 0; i < queue_size; ++i) {
                int stop = q.front();
                q.pop();

                for (int bus : stop_to_buses[stop]) {
                    if (visited_buses.count(bus)) continue;
                    visited_buses.insert(bus);

                    for (int next_stop : routes[bus]) {
                        if (next_stop == target) return buses_taken;

                        if (!visited_stops.count(next_stop)) {
                            visited_stops.insert(next_stop);
                            q.push(next_stop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};
