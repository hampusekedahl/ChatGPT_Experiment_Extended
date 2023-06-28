class Solution {
    public boolean isSubsequence(String s, String t) {
        if (s.length() == 0) {
            return true;
        }

        int pointerS = 0, pointerT = 0;
        
        while (pointerT < t.length()) {
            if (s.charAt(pointerS) == t.charAt(pointerT)) {
                pointerS++;
                if (pointerS == s.length()) {
                    return true;
                }
            }
            pointerT++;
        }
        
        return false;
    }
}

