#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int plantedFlowers = 0;
        
        for (int i = 0; i < flowerbed.size() && plantedFlowers < n; ++i) {
            if (flowerbed[i] == 0 && 
                (i == 0 || flowerbed[i - 1] == 0) && 
                (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                ++plantedFlowers;
            }
        }
        
        return plantedFlowers >= n;
    }
};