#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<queue<int>> waiting(26);
        int count = 0;
        
        for (const auto& word : words) {
            waiting[word[0] - 'a'].push(word.size() << 8);
        }
        
        for (const char c : s) {
            queue<int>& q = waiting[c - 'a'];
            int size = q.size();
            while (size-- > 0) {
                int top = q.front();
                q.pop();
                int idx = top >> 8;
                int pos = top & 0xff;
                if (++pos >= idx) {
                    count++;
                } else {
                    waiting[words[idx - 1][pos] - 'a'].push((idx << 8) | pos);
                }
            }
        }
        
        return count;
    }
};