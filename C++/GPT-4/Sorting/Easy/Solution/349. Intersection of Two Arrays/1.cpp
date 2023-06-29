#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Convert the vectors to sets
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());

        // Prepare a vector to store the result
        vector<int> result;

        // Use set_intersection from the STL. 
        // We need to provide it an output iterator that appends to the result vector.
        // std::back_inserter does exactly this.
        std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(result));
        
        return result;
    }
};
