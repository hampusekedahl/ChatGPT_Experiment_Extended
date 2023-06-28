class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> parent(accounts.size());
        unordered_map<string, int> emailToIndex;
        unordered_map<string, string> emailToName;
        for (int i = 0; i < accounts.size(); i++) {
            parent[i] = i;
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToIndex.count(email) == 0) {
                    emailToIndex[email] = i;
                } else {
                    parent[find(emailToIndex[email], parent)] = i;
                }
                emailToName[email] = accounts[i][0];
            }
        }
        unordered_map<int, set<string>> groups;
        for (const auto& [email, _] : emailToIndex) {
            groups[find(emailToIndex[email], parent)].insert(email);
        }
        vector<vector<string>> result;
        for (const auto& [_, emails] : groups) {
            vector<string> account(emails.begin(), emails.end());
            account.insert(account.begin(), emailToName[*emails.begin()]);
            result.push_back(account);
        }
        return result;
    }

private:
    int find(int x, vector<int>& parent) {
        if (x != parent[x]) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
};
