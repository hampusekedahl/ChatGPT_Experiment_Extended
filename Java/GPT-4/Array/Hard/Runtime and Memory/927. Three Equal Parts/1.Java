class Solution {
    public int[] threeEqualParts(int[] arr) {
        int numOfOnes = 0;
        for (int bit : arr) {
            numOfOnes += bit;
        }

        // if numOfOnes % 3 != 0, no solution exists
        if (numOfOnes % 3 != 0) {
            return new int[]{-1, -1};
        }

        // if there are no 1s, the array can be split in any way
        if (numOfOnes == 0) {
            return new int[]{0, 2};
        }

        int onesPerPart = numOfOnes / 3;
        int[] indices = new int[3]; // to hold the indices where each part starts
        int count = 0;
        
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 1) {
                if (count % onesPerPart == 0) { // find the start of each part
                    indices[count / onesPerPart] = i;
                }
                count++;
            }
        }

        // compare the rest of the bits in each part
        while (indices[2] < arr.length) {
            if (arr[indices[0]] == arr[indices[1]] && arr[indices[1]] == arr[indices[2]]) {
                indices[0]++;
                indices[1]++;
                indices[2]++;
            } else {
                return new int[]{-1, -1};
            }
        }

        return new int[]{indices[0] - 1, indices[1]};
    }
}
