class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int ones = count(arr.begin(), arr.end(), 1);
        if (ones % 3 != 0) return {-1, -1};
        if (ones == 0) return {0, 2}; // special case: no ones, answer can be any two valid indices
        
        int targetOnes = ones / 3;
        int onesCount = 0;
        int start = 0, mid = 0, end = 0;
        
        for (int i = arr.size() - 1; i >= 0; --i) {
            if (arr[i] == 1) {
                ++onesCount;
                if (onesCount == targetOnes) end = i;
                else if (onesCount == 2 * targetOnes) mid = i;
                else if (onesCount == 3 * targetOnes) start = i;
            }
        }
        
        while (arr[end] == 0) { // skip trailing zeros
            ++start;
            ++mid;
            ++end;
        }
        
        while (end < arr.size()) {
            if (arr[start] != arr[mid] || arr[mid] != arr[end]) {
                return {-1, -1};
            }
            ++start;
            ++mid;
            ++end;
        }
        
        return {start - 1, mid};
    }
};
