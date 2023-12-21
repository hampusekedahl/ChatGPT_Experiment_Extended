import java.util.*;

class Solution {
    public String getPermutation(int n, int k) {
        // initialize all numbers
        ArrayList<Integer> numberList = new ArrayList<>();
        for (int i = 1; i <= n; i++){
            numberList.add(i);
        }

        // change k to be index
        k--;

        // set factorial of n
        int[] fact = new int[n];
        fact[0] = 1;
        for (int i = 1; i < n; i++){
            fact[i] = i * fact[i - 1];
        }

        // find sequence
        StringBuilder sb = new StringBuilder();
        for (int i = n; i > 0; i--){
            int index = k / fact[i - 1];
            k = k % fact[i - 1];
            sb.append(numberList.get(index));
            // remove used number
            numberList.remove(index);
        }

        return String.valueOf(sb);
    }
}
