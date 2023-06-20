class Solution {
    public boolean isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        } while (slow != fast);
        
        return slow == 1;
    }
    
    private int getNext(int n) {
        int total = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            total += d * d;
        }
        return total;
    }
}
