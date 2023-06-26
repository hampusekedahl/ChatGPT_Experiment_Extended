import java.util.*;

class WordFilter {
    private Map<String, Integer> map = new HashMap<>();

    public WordFilter(String[] words) {
        for(int index = 0; index < words.length; index++) {
            String word = words[index];
            for(int i = 0; i <= word.length(); i++) {
                for(int j = 0; j <= word.length(); j++) {
                    String str = word.substring(0, i) + '#' + word.substring(word.length() - j);
                    map.put(str, index);
                }
            }
        }
    }
    
    public int f(String pref, String suff) {
        return (map.containsKey(pref + '#' + suff)) ? map.get(pref + '#' + suff) : -1;
    }
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(pref,suff);
 */

