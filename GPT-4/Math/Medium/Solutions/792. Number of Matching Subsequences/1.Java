class Solution {
    public int numMatchingSubseq(String s, String[] words) {
        int count = 0;
        for (String word : words) {
            if (isSubsequence(s, word)) {
                count++;
            }
        }
        return count;
    }

    private boolean isSubsequence(String s, String word) {
        int j = 0;
        for (int i = 0; i < s.length() && j < word.length(); i++) {
            if (s.charAt(i) == word.charAt(j)) {
                j++;
            }
        }
        return j == word.length();
    }
}
