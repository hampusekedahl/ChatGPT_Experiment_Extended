import java.util.*;

class Solution {
    public int numMatchingSubseq(String S, String[] words) {
        Map<Character, Deque<String>> waiting = new HashMap<>();
        for (char c = 'a'; c <= 'z'; c++)
            waiting.put(c, new LinkedList<String>());
        for (String w : words)
            waiting.get(w.charAt(0)).addLast(w);
        int count = 0;
        for (char c : S.toCharArray()) {
            Deque<String> advance = waiting.get(c);
            int size = advance.size();
            for (int i = 0; i < size; ++i) {
                String w = advance.removeFirst();
                if (w.length() == 1) 
                    count++;
                else 
                    waiting.get(w.charAt(1)).addLast(w.substring(1));
            }
        }
        return count;
    }
}
