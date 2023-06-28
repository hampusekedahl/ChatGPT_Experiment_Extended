class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int ones = count(arr.begin(), arr.end(), 1);
        if (ones % 3 != 0) return {-1, -1};
        if (ones == 0) return {0, 2};
        
        ones /= 3;
        int n = arr.size();
        vector<int> idx(3);
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(arr[i] == 1) {
                if(count % ones == 0) idx[count / ones] = i;
                ++count;
            }
        }
        
        while(idx[2] < n) {
            if(arr[idx[0]] == arr[idx[1]] && arr[idx[1]] == arr[idx[2]]) {
                ++idx[0], ++idx[1], ++idx[2];
            } else {
                return {-1, -1};
            }
        }
        return {idx[0] - 1, idx[1]};
    }
};
