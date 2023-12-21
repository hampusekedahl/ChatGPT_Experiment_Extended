import java.util.Arrays;

class Solution {
    public String largestMultipleOfThree(int[] digits) {
        int[] count = new int[10];
        int[] remainder = new int[]{0, 1, 2, 0, 1, 2, 0, 1, 2, 0};
        int[] sum = new int[3];
        int total = 0;
        
        for (int digit : digits) {
            count[digit]++;
            sum[remainder[digit]]++;
            total += digit;
        }
        
        while (total % 3 != 0) {
            for (int i = total % 3; i <= 9; i += 3) {
                if (count[i] != 0) {
                    count[i]--;
                    sum[i % 3]--;
                    total -= i;
                    break;
                }
            }
        }
        
        if (count[0] == digits.length) {
            return "0";
        }
        
        StringBuilder sb = new StringBuilder();
        for (int i = 9; i >= 0; i--) {
            while (count[i]-- > 0) {
                sb.append(i);
            }
        }
        
        return sb.toString();
    }
}
