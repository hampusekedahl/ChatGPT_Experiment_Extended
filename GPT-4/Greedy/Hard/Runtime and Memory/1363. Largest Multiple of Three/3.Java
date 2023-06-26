import java.util.Arrays;

class Solution {
    public String largestMultipleOfThree(int[] digits) {
        int[] count = new int[10];
        int[] remainder = new int[]{0, 1, 2, 0, 1, 2, 0, 1, 2, 0};
        int total = 0;
        
        for (int digit : digits) {
            count[digit]++;
            total += digit;
        }
        
        while (total % 3 != 0) {
            int r = total % 3;
            for (int i = r; i <= 9; i += 3) {
                if (count[i] > 0) {
                    count[i]--;
                    total -= i;
                    break;
                }
            }

            if (total % 3 == 0) break;

            r = 3 - r;
            int needToRemove = 2;
            for (int i = r % 3; i <= 9 && needToRemove > 0; i += 3) {
                while (count[i] > 0 && needToRemove > 0) {
                    count[i]--;
                    total -= i;
                    needToRemove--;
                }
            }
        }
        
        if (total == 0) {
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
