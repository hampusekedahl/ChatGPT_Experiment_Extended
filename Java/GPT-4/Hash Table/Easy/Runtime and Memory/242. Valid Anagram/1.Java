class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        int[] counter = new int[26]; // For each letter in the alphabet
        for (int i = 0; i < s.length(); i++) {
            counter[s.charAt(i) - 'a']++;  // Increment the count of the character in s
            counter[t.charAt(i) - 'a']--;  // Decrement the count of the character in t
        }

        for (int count : counter) {
            if (count != 0) {
                return false;  // If the count is not zero, s and t are not anagrams
            }
        }

        return true;
    }
}
