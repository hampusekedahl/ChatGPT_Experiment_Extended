import java.util.*;

class Solution {
    public String largestMultipleOfThree(int[] digits) {
        // sort digits in descending order
        Integer[] arr = Arrays.stream(digits).boxed().toArray(Integer[]::new);
        Arrays.sort(arr, Collections.reverseOrder());

        int remainder = Arrays.stream(digits).sum() % 3;

        if (remainder != 0) {
            int i = arr.length - 1;
            while (i >= 0 && arr[i] % 3 != remainder) {
                i--;
            }
            if (i >= 0) {
                // remove one digit that makes the total sum divisible by 3
                arr = removeElement(arr, i);
            } else {
                // if no such digit, remove smallest two digits that makes the total sum divisible by 3
                i = arr.length - 1;
                int count = 0;
                while (i >= 0 && count < 2) {
                    if (arr[i] % 3 == 3 - remainder) {
                        arr = removeElement(arr, i);
                        count++;
                    }
                    i--;
                }
                if (count < 2) return "";  // return empty string if no answer
            }
        }

        // return the result as a string without leading zeros
        StringBuilder sb = new StringBuilder();
        for (int num : arr) {
            sb.append(num);
        }
        return sb.toString().replaceFirst("^0+(?!$)", "");
    }

    private Integer[] removeElement(Integer[] arr, int index) {
        Integer[] newArray = new Integer[arr.length - 1];
        System.arraycopy(arr, 0, newArray, 0, index);
        System.arraycopy(arr, index + 1, newArray, index, arr.length - index - 1);
        return newArray;
    }
}
