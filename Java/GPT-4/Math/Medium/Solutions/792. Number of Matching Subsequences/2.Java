import java.util.*;

class Solution {
    public int numMatchingSubseq(String s, String[] words) {
        List<Integer>[] idx = new List[26]; // Just like a bucket sort
        for (int i = 0; i < s.length(); i++) {
            if (idx[s.charAt(i) - 'a'] == null) 
                idx[s.charAt(i) - 'a'] = new ArrayList<>();
            idx[s.charAt(i) - 'a'].add(i);
        }
        int count = 0;
        for (String word : words) {
            if (isSubsequence(word, idx)) 
                count++;
        }
        return count;
    }

    private boolean isSubsequence(String word, List<Integer>[] idx) {
        int x = 0;
        for (char c : word.toCharArray()) {
            int i = c - 'a';
            if (idx[i] == null) 
                return false; // No such character in s.
            int pos = Collections.binarySearch(idx[i], x);
            if (pos < 0) 
                pos = -(pos + 1);
            if (pos == idx[i].size()) 
                return false; // x is larger than any index in idx[i].
            x = idx[i].get(pos) + 1; // Update x to the next possible index.
        }
        return true;
    }
}
