class Solution {
    public int strongPasswordChecker(String s) {
        int res = 0, a = 1, A = 1, d = 1;
        char[] ca = s.toCharArray();
        int[] arr = new int[ca.length];
        
        for (int i = 0; i < arr.length;) {
            if (Character.isLowerCase(ca[i])) a = 0;
            if (Character.isUpperCase(ca[i])) A = 0;
            if (Character.isDigit(ca[i])) d = 0;
            
            int j = i;
            while (i < ca.length && ca[i] == ca[j]) i++;
            arr[j] = i - j;
        }
        
        int total_missing = (a + A + d);

        if (ca.length < 6) {
            res += total_missing + Math.max(0, 6 - (ca.length + total_missing));
            
        } else {
            int over_len = Math.max(ca.length - 20, 0), left_over = 0;
            res += over_len;

            for (int k = 1; k < 3; k++) {
                for (int i = 0; i < arr.length && over_len > 0; i++) {
                    if (arr[i] < 3 || arr[i] % 3 != (k - 1)) continue;
                    arr[i] -= Math.min(over_len, k);
                    over_len -= k;
                }
            }

            for (int i = 0; i < arr.length; i++) {
              if (arr[i] >= 3 && over_len > 0) {
                int need = arr[i] - 2;
                arr[i] -= over_len;
                over_len -= need;
              }

              if (arr[i] >= 3) left_over += arr[i] / 3;
            }

            res += Math.max(total_missing, left_over);
        }

        return res;
    }
}

