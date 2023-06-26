import java.util.*;

class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (pattern.length() != words.length) return false;

        HashMap<Character, String> mapCharToStr = new HashMap<>();
        HashMap<String, Character> mapStrToChar = new HashMap<>();

        for (int i = 0; i < words.length; i++) {
            char c = pattern.charAt(i);
            String w = words[i];
            if (!mapCharToStr.containsKey(c)) {
                if (mapStrToChar.containsKey(w)) {
                    return false;
                } else {
                    mapCharToStr.put(c, w);
                    mapStrToChar.put(w, c);
                }

            } else {
                String mappedStr = mapCharToStr.get(c);
                if (!mappedStr.equals(w)) {
                    return false;
                }
            }
        }

        return true;
    }
}

