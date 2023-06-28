#include <vector>
#include <deque>
#include <limits>

class Solution {
public:
    int shortestSubarray(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> prefix_sum(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
        
        std::deque<int> deque;
        int min_length = std::numeric_limits<int>::max();
        
        for (int i = 0; i < prefix_sum.size(); i++) {
            while (!deque.empty() && prefix_sum[i] - prefix_sum[deque.front()] >= k) {
                min_length = std::min(min_length, i - deque.front());
                deque.pop_front();
            }
            
            while (!deque.empty() && prefix_sum[i] <= prefix_sum[deque.back()]) {
                deque.pop_back();
            }
            
            deque.push_back(i);
        }
        
        return (min_length == std::numeric_limits<int>::max()) ? -1 : min_length;
    }
};
