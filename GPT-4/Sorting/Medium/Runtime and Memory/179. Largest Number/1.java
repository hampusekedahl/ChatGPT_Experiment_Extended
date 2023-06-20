class Solution {
    public String largestNumber(int[] nums) {
        // Convert the integer array to a string array
        String[] strs = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            strs[i] = String.valueOf(nums[i]);
        }
        
        // Sort the string array
        Arrays.sort(strs, new Comparator<String>() {
            public int compare(String s1, String s2) {
                String order1 = s1 + s2;
                String order2 = s2 + s1;
                return order2.compareTo(order1);  // descending order
            }
        });
        
        // Special case: If the largest number is '0', the whole number is zero
        if (strs[0].equals("0")) {
            return "0";
        }
        
        // Concatenate all numbers into a string
        StringBuilder sb = new StringBuilder();
        for (String str : strs) {
            sb.append(str);
        }
        return sb.toString();
    }
}
