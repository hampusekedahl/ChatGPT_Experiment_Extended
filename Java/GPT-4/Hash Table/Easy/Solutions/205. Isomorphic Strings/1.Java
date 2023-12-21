import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Character> sToTMap = new HashMap<>();
        Map<Character, Character> tToSMap = new HashMap<>();

        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            char sChar = s.charAt(i);
            char tChar = t.charAt(i);

            if (sToTMap.containsKey(sChar)) {
                if (sToTMap.get(sChar) != tChar) {
                    return false;
                }
            } else {
                if (tToSMap.containsKey(tChar)) {
                    return false;
                }
                sToTMap.put(sChar, tChar);
                tToSMap.put(tChar, sChar);
            }
        }
        return true;
    }
}
