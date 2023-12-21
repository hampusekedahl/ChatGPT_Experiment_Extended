class Solution {
    public char findTheDifference(String s, String t) {
        char xor = 0;
        for (char c : s.toCharArray()) {
            xor ^= c;
        }
        for (char c : t.toCharArray()) {
            xor ^= c;
        }
        return xor;
    }
}
