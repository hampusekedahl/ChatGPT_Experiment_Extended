public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid; // look on the left side of mid
            } else {
                left = mid + 1; // look on the right side of mid
            }
        }
        // at this point, 'left' and 'right' should be pointing at the same spot
        return left;
    }
}
