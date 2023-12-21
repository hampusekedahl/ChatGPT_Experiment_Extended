class Solution {
    public int[] diStringMatch(String s) {
        int n = s.length(), left = 0, right = n;
        int[] result = new int[n + 1];
        
        for(int i = 0; i < n; i++) {
            if(s.charAt(i) == 'I') {
                result[i] = left++;
            } else {
                result[i] = right--;
            }
        }
        
        // the last number to add would be either 'left' or 'right' since they're equal
        result[n] = left;  
        return result;
    }
}
