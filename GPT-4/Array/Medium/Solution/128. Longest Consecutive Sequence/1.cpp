#include <vector>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> num_set;
        
        for (int num : nums) {
            num_set.insert(num);
        }

        int longest_streak = 0;

        for (int num : num_set) {
            if (num_set.find(num - 1) == num_set.end()) {
                int current_num = num;
                int current_streak = 1;

                while (num_set.find(current_num + 1) != num_set.end()) {
                    current_num += 1;
                    current_streak += 1;
                }

                longest_streak = std::max(longest_streak, current_streak);
            }
        }

        return longest_streak;
    }
};
