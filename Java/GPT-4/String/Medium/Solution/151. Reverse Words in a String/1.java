import java.util.Arrays;
import java.util.Collections;

class Solution {
    public String reverseWords(String s) {
        // Split the string by one or more spaces.
        String[] words = s.trim().split("\\s+");
        
        // Reverse the array of words.
        Collections.reverse(Arrays.asList(words));
        
        // Join the words with a space and return.
        return String.join(" ", words);
    }
}

