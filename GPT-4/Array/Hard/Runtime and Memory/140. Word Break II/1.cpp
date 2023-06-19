#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;
        return wordBreakHelper(s, dict, memo);
    }

    vector<string> wordBreakHelper(string& s, unordered_set<string>& dict, unordered_map<string, vector<string>>& memo) {
        if (memo.count(s)) {
            return memo[s];
        }

        vector<string> result;

        if (s.empty()) {
            result.push_back("");
            return result;
        }

        for (int i = 1; i <= s.size(); ++i) {
            string word = s.substr(0, i);
            if (dict.count(word)) {
                string remaining = s.substr(i);
                vector<string> sub_result = wordBreakHelper(remaining, dict, memo);
                for (const string& str : sub_result) {
                    string space = str.empty() ? "" : " ";
                    result.push_back(word + space + str);
                }
            }
        }

        memo[s] = result;
        return result;
    }
};
