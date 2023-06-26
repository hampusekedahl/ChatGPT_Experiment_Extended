import java.util.*;

class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (pattern.length() != words.length) {
            return false;
        }

        Map<Character, String> patternToWord = new HashMap<>();
        Set<String> usedWords = new HashSet<>();

        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern.charAt(i);
            if (patternToWord.containsKey(c)) {
                if (!patternToWord.get(c).equals(words[i])) {
                    return false;
                }
            } else if (usedWords.contains(words[i])) {
                return false;
            } else {
                patternToWord.put(c, words[i]);
                usedWords.add(words[i]);
            }
        }

        return true;
    }
}

