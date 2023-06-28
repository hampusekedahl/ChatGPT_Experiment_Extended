class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> indices(26);
        for (int i = 0; i < s.size(); ++i) {
            indices[s[i] - 'a'].push_back(i);
        }
        
        int count = 0;
        for (const string& word : words) {
            if (isSubsequence(word, indices)) {
                count++;
            }
        }
        
        return count;
    }

private:
    bool isSubsequence(const string& word, const vector<vector<int>>& indices) {
        int prev_index = -1;
        for (char c : word) {
            const vector<int>& char_indices = indices[c - 'a'];
            auto it = upper_bound(char_indices.begin(), char_indices.end(), prev_index);
            if (it == char_indices.end()) {
                return false;
            }
            prev_index = *it;
        }
        return true;
    }
};
