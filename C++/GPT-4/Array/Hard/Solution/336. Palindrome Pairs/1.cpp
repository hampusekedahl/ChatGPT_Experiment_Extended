#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<int>> palindromePairs(std::vector<std::string>& words) {
        std::unordered_map<std::string, int> word_map;
        for (int i = 0; i < words.size(); ++i) {
            std::string key = words[i];
            std::reverse(key.begin(), key.end());
            word_map[key] = i;
        }

        std::vector<std::vector<int>> result;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].size(); ++j) {
                std::string left = words[i].substr(0, j);
                std::string right = words[i].substr(j);

                if (isPalindrome(left) && word_map.count(right) && word_map[right] != i) {
                    result.push_back({word_map[right], i});
                }

                if (!right.empty() && isPalindrome(right) && word_map.count(left) && word_map[left] != i) {
                    result.push_back({i, word_map[left]});
                }
            }
        }
        return result;
    }

    bool isPalindrome(const std::string& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};
