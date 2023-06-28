#include <iostream>
using namespace std;

class Solution {
public:
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int digit = n % 10;
            n = n / 10;
            totalSum += digit * digit;
        }
        return totalSum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
};