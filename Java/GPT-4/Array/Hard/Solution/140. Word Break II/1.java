import java.util.*;

class Solution {
    private Map<Integer, List<String>> memo = new HashMap<>();

    public List<String> wordBreak(String s, List<String> wordDict) {
        Set<String> wordSet = new HashSet<>(wordDict);
        return wordBreak(s, wordSet, 0);
    }

    private List<String> wordBreak(String s, Set<String> wordSet, int start) {
        if (memo.containsKey(start)) {
            return memo.get(start);
        }

        List<String> results = new ArrayList<>();
        if (start == s.length()) {
            results.add("");
        }
        for (int end = start + 1; end <= s.length(); end++) {
            if (wordSet.contains(s.substring(start, end))) {
                List<String> list = wordBreak(s, wordSet, end);
                for (String l : list) {
                    results.add(s.substring(start, end) + (l.equals("") ? "" : " ") + l);
                }
            }
        }
        memo.put(start, results);
        return results;
    }
}

