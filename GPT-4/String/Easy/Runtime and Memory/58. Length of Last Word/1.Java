class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim(); // Remove any trailing spaces
        int lastSpaceIndex = s.lastIndexOf(" "); // Find the last space character
        return s.length() - lastSpaceIndex - 1; // Compute the length of the last word
    }
}
