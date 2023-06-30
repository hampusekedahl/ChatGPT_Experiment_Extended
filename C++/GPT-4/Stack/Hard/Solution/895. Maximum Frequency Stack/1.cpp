class FreqStack {
private:
    unordered_map<int, int> freq; // Element -> Frequency mapping
    unordered_map<int, stack<int>> m; // Frequency -> Stack of elements mapping
    int maxfreq = 0; // Maximum frequency

public:
    FreqStack() {}

    void push(int val) {
        maxfreq = max(maxfreq, ++freq[val]);
        m[freq[val]].push(val);
    }
    
    int pop() {
        int top = m[maxfreq].top();
        m[maxfreq].pop();
        if (m[freq[top]--].empty()) maxfreq--;
        return top;
    }
};
