class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder sb = new StringBuilder();
        
        for (char c : s.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                sb.append(Character.toLowerCase(c));
            }
        }
        
        String cleanedString = sb.toString();
        String reversedString = sb.reverse().toString();
        
        return cleanedString.equals(reversedString);
    }
}

