#include <unordered_map>
#include <stack>

class FreqStack {
public:
    FreqStack() : maxFrequency(0) {
        
    }
    
    void push(int val) {
        int frequency = ++frequencyMap[val];
        if (frequency > maxFrequency) {
            maxFrequency = frequency;
        }
        stackMap[frequency].push(val);
    }
    
    int pop() {
        int val = stackMap[maxFrequency].top();
        stackMap[maxFrequency].pop();
        if (stackMap[maxFrequency].empty()) {
            maxFrequency--;
        }
        if (--frequencyMap[val] == 0) {
            frequencyMap.erase(val);
        }
        return val;
    }
    
private:
    std::unordered_map<int, int> frequencyMap;
    std::unordered_map<int, std::stack<int>> stackMap;
    int maxFrequency;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
