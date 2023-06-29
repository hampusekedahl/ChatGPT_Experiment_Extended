class TrieNode {
public:
    vector<TrieNode*> children;
    int weight;
    TrieNode() {
        children = vector<TrieNode*>(27, nullptr);
        weight = 0;
    }
};

class WordFilter {
private:
    TrieNode* trie;

    void insert(string word, int weight) {
        TrieNode* node = trie;
        node->weight = weight;
        for (int i = word.size(); i >= 0; --i) {
            TrieNode* next_node = node->children[word[i] - 'a'];
            if (!next_node) {
                next_node = new TrieNode();
                node->children[word[i] - 'a'] = next_node;
            }
            node = next_node;
            node->weight = weight;
        }
    }

public:
    WordFilter(vector<string>& words) {
        trie = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            for (int j = 0; j <= word.size(); ++j)
                insert(word.substr(j) + "{" + words[i], i);
        }
    }
    
    int f(string prefix, string suffix) {
        TrieNode* node = trie;
        string word = suffix + "{" + prefix;
        for (char c : word) {
            TrieNode* next_node = node->children[c - 'a'];
            if (!next_node)
                return -1;
            node = next_node;
        }
        return node->weight;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
