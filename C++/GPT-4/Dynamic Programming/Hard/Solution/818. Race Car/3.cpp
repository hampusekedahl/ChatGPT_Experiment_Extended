class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int>> q;
        unordered_map<int, unordered_set<int>> visited;
        q.push({0, 1});
        visited[0].insert(1);
        int steps = 0;
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [pos, speed] = q.front(); q.pop();
                if (pos == target) return steps;
                auto nextStates = vector<pair<int, int>>{{pos + speed, speed * 2}, {pos, speed > 0 ? -1 : 1}};
                for (auto& [nextPos, nextSpeed] : nextStates) {
                    if (abs(nextPos) > 2 * target) continue;
                    if (!visited[nextPos].count(nextSpeed)) {
                        q.push({nextPos, nextSpeed});
                        visited[nextPos].insert(nextSpeed);
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};
