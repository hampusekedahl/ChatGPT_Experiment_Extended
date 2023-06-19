#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> reversedWords;
        vector<vector<int>> result;

        for (int i = 0; i < words.size(); ++i) {
            string reversedWord = words[i];
            reverse(reversedWord.begin(), reversedWord.end());
            reversedWords[reversedWord] = i;
        }

        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].size(); ++j) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);

                if (isPalindrome(left) && reversedWords.count(right) && reversedWords[right] != i) {
                    result.push_back({reversedWords[right], i});
                }

                if (!right.empty() && isPalindrome(right) && reversedWords.count(left) && reversedWords[left] != i) {
                    result.push_back({i, reversedWords[left]});
                }
            }
        }

        return result;
    }

    bool isPalindrome(const string& s) {
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
