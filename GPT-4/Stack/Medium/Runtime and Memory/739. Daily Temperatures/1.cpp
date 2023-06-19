#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> tempStack;
        
        for (int i = 0; i < n; ++i) {
            while (!tempStack.empty() && temperatures[i] > temperatures[tempStack.top()]) {
                int index = tempStack.top();
                tempStack.pop();
                result[index] = i - index;
            }
            tempStack.push(i);
        }
        
        return result;
    }
};
