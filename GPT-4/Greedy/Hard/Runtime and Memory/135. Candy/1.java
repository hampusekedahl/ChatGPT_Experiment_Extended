class Solution {
    public int candy(int[] ratings) {
        int[] left = new int[ratings.length];
        int[] right = new int[ratings.length];

        // Left to right scan
        left[0] = 1;
        for (int i = 1; i < ratings.length; i++) {
            left[i] = (ratings[i] > ratings[i - 1]) ? left[i - 1] + 1 : 1;
        }

        // Right to left scan
        right[ratings.length - 1] = 1;
        for (int i = ratings.length - 2; i >= 0; i--) {
            right[i] = (ratings[i] > ratings[i + 1]) ? right[i + 1] + 1 : 1;
        }

        // Summing up the max of both
        int totalCandies = 0;
        for (int i = 0; i < ratings.length; i++) {
            totalCandies += Math.max(left[i], right[i]);
        }

        return totalCandies;
    }
}

