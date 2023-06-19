// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int mid;

        while (left < right) {
            mid = left + (right - left) / 2;

            if (isBadVersion(mid)) {
                right = mid; // If the current version is bad, the first bad version should be to the left.
            } else {
                left = mid + 1; // If the current version is good, the first bad version should be to the right.
            }
        }

        // When left and right converge, we have found the first bad version.
        return left;
    }
};
