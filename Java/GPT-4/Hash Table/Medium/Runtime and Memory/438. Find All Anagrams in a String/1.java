import java.util.*;

class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> result = new ArrayList<>();
        if (s == null || s.length() == 0 || p.length() > s.length()) return result;

        int[] pCount = new int[26];
        int[] sCount = new int[26];

        // fill the pCount array with the frequency of each character in 'p'
        for (char c : p.toCharArray()) {
            pCount[c - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            // add the current character to the sCount array
            sCount[s.charAt(i) - 'a']++;

            // remove the character at the beginning of the window
            if (i >= p.length()) {
                sCount[s.charAt(i - p.length()) - 'a']--;
            }

            // if sCount and pCount are identical, we found an anagram
            if (Arrays.equals(sCount, pCount)) {
                result.add(i - p.length() + 1);
            }
        }

        return result;
    }
}

