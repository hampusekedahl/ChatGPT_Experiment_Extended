#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
        std::unordered_map<std::string, std::vector<std::string>> memo;
        return wordBreakHelper(s, dict, memo);
    }

    std::vector<std::string> wordBreakHelper(std::string s, std::unordered_set<std::string>& dict, std::unordered_map<std::string, std::vector<std::string>>& memo) {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }

        std::vector<std::string> result;

        if (dict.find(s) != dict.end()) {
            result.push_back(s);
        }

        for (int i = 1; i < s.length(); ++i) {
            std::string word = s.substr(0, i);
            if (dict.find(word) != dict.end()) {
                std::string remaining = s.substr(i);
                std::vector<std::string> subResult = wordBreakHelper(remaining, dict, memo);
                for (const std::string& sub : subResult) {
                    result.push_back(word + " " + sub);
                }
            }
        }

        memo[s] = result;
        return result;
    }
};
