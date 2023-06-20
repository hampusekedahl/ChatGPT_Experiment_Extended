import java.util.*;

class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        return dfs(s, wordDict, new HashMap<>());
    }

    private List<String> dfs(String s, List<String> wordDict, Map<String, List<String>> map) {
        if (map.containsKey(s)) {
            return map.get(s);
        }
        
        List<String> results = new ArrayList<>();
        if (s.length() == 0) {
            results.add("");
            return results;
        }
        
        for (String word : wordDict) {
            if (s.startsWith(word)) {
                List<String> subList = dfs(s.substring(word.length()), wordDict, map);
                for (String sub : subList) {
                    results.add(word + (sub.isEmpty() ? "" : " ") + sub);
                }
            }
        }
        
        map.put(s, results);
        return results;
    }
}
