import java.util.*;

class WordFilter {

    private TrieNode root;
    
    public WordFilter(String[] words) {
        root = new TrieNode();
        for (int weight = 0; weight < words.length; weight++) {
            String word = words[weight] + '{';
            for (int i = 0; i < word.length(); i++) {
                TrieNode node = root;
                node.weight = weight;
                for (int j = i; j < 2 * word.length() - 1; j++) {
                    int k = word.charAt(j % word.length()) - 'a';
                    if (node.children[k] == null)
                        node.children[k] = new TrieNode();
                    node = node.children[k];
                    node.weight = weight;
                }
            }
        }
    }
    
    public int f(String prefix, String suffix) {
        TrieNode node = root;
        for (char letter : (suffix + '{' + prefix).toCharArray()) {
            if (node.children[letter - 'a'] == null)
                return -1;
            node = node.children[letter - 'a'];
        }
        return node.weight;
    }

    private class TrieNode {
        private TrieNode[] children;
        private int weight;
        public TrieNode() {
            children = new TrieNode[27];
            weight = 0;
        }
    }
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(pref,suff);
 */

