import java.util.*;

class Solution {
    public int numMatchingSubseq(String s, String[] words) {
        List<Queue<Integer>> idxs = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            idxs.add(new LinkedList<>());
        }
        for (int i = 0; i < s.length(); i++) {
            idxs.get(s.charAt(i) - 'a').offer(i);
        }
        int count = 0;
        for (String word : words) {
            int lastIdx = -1;
            boolean isSubseq = true;
            for (char c : word.toCharArray()) {
                Queue<Integer> q = idxs.get(c - 'a');
                while (!q.isEmpty() && q.peek() <= lastIdx) {
                    q.poll();
                }
                if (q.isEmpty()) {
                    isSubseq = false;
                    break;
                } else {
                    lastIdx = q.poll();
                }
            }
            if (isSubseq) count++;
        }
        return count;
    }
}
