class TrieNode {
public:
    TrieNode* children[27];
    int index;
    
    TrieNode() {
        for (auto &child : children)
            child = nullptr;
        index = 0;
    }
};

class WordFilter {
private:
    TrieNode* root;
    
    void insert(const string &word, int index) {
        TrieNode* node = root;
        string key = word + "{" + word;
        
        for (int i = 0; i < word.size(); ++i) {
            for (int j = i; j < 2*word.size(); ++j) {
                int c = key[j] - 'a';
                if (!node->children[c])
                    node->children[c] = new TrieNode();
                node = node->children[c];
                node->index = index;
            }
            node = root;
        }
    }

public:
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); ++i)
            insert(words[i], i);
    }
    
    int f(string pref, string suff) {
        TrieNode* node = root;
        string key = pref + "{" + suff;
        
        for (char c : key) {
            if (!node->children[c - 'a'])
                return -1;
            node = node->children[c - 'a'];
        }
        
        return node->index;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
