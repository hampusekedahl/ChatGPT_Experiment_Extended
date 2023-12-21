class Solution {
    public boolean isIsomorphic(String s, String t) {
        int[] mappingDictStoT = new int[256];
        int[] mappingDictTtoS = new int[256];
        for (int i = 0; i < s.length(); i++) {
            char chS = s.charAt(i);
            char chT = t.charAt(i);
            if (mappingDictStoT[chS] == 0 && mappingDictTtoS[chT] == 0) {
                mappingDictStoT[chS] = chT;
                mappingDictTtoS[chT] = chS;
            } else {
                if (mappingDictStoT[chS] != chT || mappingDictTtoS[chT] != chS) {
                    return false;
                }
            }
        }
        return true;
    }
}
