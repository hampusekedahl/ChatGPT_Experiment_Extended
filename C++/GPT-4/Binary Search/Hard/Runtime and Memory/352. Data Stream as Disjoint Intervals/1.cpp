#include <map>
#include <vector>
using namespace std;

class SummaryRanges {
public:
    map<int, int> intervals;
    SummaryRanges() {

    }
    
    void addNum(int value) {
        auto it = intervals.upper_bound(value);
        int start = value, end = value;
        if(it != intervals.begin() && prev(it)->second + 1 >= value) it--;
        while(it != intervals.end() && value + 1 >= it->first && value - 1 <= it->second) {
            start = min(start, it->first);
            end = max(end, it->second);
            it = intervals.erase(it);
        }
        intervals[start] = end;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for(auto& i : intervals) {
            result.push_back({i.first, i.second});
        }
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
