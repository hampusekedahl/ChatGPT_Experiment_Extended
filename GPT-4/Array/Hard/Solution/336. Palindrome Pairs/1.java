import java.util.*;

class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        List<List<Integer>> result = new ArrayList<>();
        if(words == null || words.length < 2) {
            return result;
        }
        
        Map<String, Integer> map = new HashMap<>();
        for(int i = 0; i < words.length; i++) {
            map.put(words[i], i);
        }
        
        for(int i = 0; i < words.length; i++) {
            for(int j = 0; j <= words[i].length(); j++) { // Notice it should be "j <= words[i].length()"
                String str1 = words[i].substring(0, j);
                String str2 = words[i].substring(j);
                
                if(isPalindrome(str1)) {
                    String str2Rev = new StringBuilder(str2).reverse().toString();
                    if(map.containsKey(str2Rev) && map.get(str2Rev) != i) {
                        List<Integer> list = new ArrayList<>();
                        list.add(map.get(str2Rev));
                        list.add(i);
                        result.add(list);
                    }
                }
                
                if(isPalindrome(str2)) {
                    String str1Rev = new StringBuilder(str1).reverse().toString();
                    // check "str.length() != 0" to avoid duplicates
                    if(map.containsKey(str1Rev) && map.get(str1Rev) != i && str2.length() != 0) { 
                        List<Integer> list = new ArrayList<>();
                        list.add(i);
                        list.add(map.get(str1Rev));
                        result.add(list);
                    }
                }
            }
        }
        return result;
    }
    
    private boolean isPalindrome(String str) {
        int left = 0;
        int right = str.length() - 1;
        while(left <= right) {
            if(str.charAt(left++) != str.charAt(right--)) {
                return false;
            }
        }
        return true;
    }
}

