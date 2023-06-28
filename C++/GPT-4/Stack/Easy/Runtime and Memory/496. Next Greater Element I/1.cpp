#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> nextGreater;
        
        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                nextGreater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextGreater.count(num) ? nextGreater[num] : -1);
        }
        return ans;
    }
};
