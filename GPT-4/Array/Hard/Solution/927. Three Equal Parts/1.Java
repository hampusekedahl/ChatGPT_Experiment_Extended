class Solution {
    public int[] threeEqualParts(int[] arr) {
        int countOnes = 0;
        for (int num : arr) {
            if (num == 1)
                countOnes++;
        }

        if (countOnes == 0)
            return new int[]{0, 2};

        if (countOnes % 3 != 0)
            return new int[]{-1, -1};

        int onesInEachPart = countOnes / 3;
        int index1 = -1, index2 = -1, index3 = -1;
        int count = 0;

        for (int i = arr.length - 1; i >= 0; i--) {
            if (arr[i] == 1) {
                count++;
                if (count == 1)
                    index3 = i;
                else if (count == onesInEachPart + 1)
                    index2 = i;
                else if (count == 2 * onesInEachPart + 1) {
                    index1 = i;
                    break;
                }
            }
        }

        int zerosAfterThirdPart = arr.length - index3 - 1;
        int zerosBetweenParts = index2 - index1 - 1;

        if (zerosAfterThirdPart != zerosBetweenParts)
            return new int[]{-1, -1};

        int trailingZeros = arr.length - index3 - zerosAfterThirdPart;
        if (trailingZeros != zerosBetweenParts)
            return new int[]{-1, -1};

        return new int[]{index1 + onesInEachPart - 1, index2 + onesInEachPart};
    }
}
