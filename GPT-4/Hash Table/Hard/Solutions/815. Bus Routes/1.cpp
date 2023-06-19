#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        
        unordered_map<int, unordered_set<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].insert(i);
            }
        }

        queue<pair<int, int>> bfsQueue; // {stop, steps}
        bfsQueue.push({source, 0});
        unordered_set<int> visitedStops;
        visitedStops.insert(source);

        while (!bfsQueue.empty()) {
            int currentStop = bfsQueue.front().first;
            int steps = bfsQueue.front().second;
            bfsQueue.pop();

            for (int route : stopToRoutes[currentStop]) {
                for (int nextStop : routes[route]) {
                    if (visitedStops.find(nextStop) == visitedStops.end()) {
                        if (nextStop == target) return steps + 1;
                        visitedStops.insert(nextStop);
                        bfsQueue.push({nextStop, steps + 1});
                    }
                }
                // Remove the route after processing to avoid revisiting
                routes[route].clear();
            }
        }

        return -1;
    }
};
