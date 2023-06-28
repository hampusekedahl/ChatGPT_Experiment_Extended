class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int tail = x % 10;
            
            // Check for overflow before the multiplication and addition
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && tail > 7)) return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && tail < -8)) return 0;
            
            result = result * 10 + tail;
            x = x / 10;
        }
        return result;
    }
};
