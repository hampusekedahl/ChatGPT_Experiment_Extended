import java.util.*;

class FreqStack {
    HashMap<Integer, Integer> freq = new HashMap<>();
    HashMap<Integer, Stack<Integer>> group = new HashMap<>();
    int maxFreq = 0;

    public FreqStack() {
        
    }
    
    public void push(int val) {
        int f = freq.getOrDefault(val, 0) + 1;
        freq.put(val, f);
        if (f > maxFreq)
            maxFreq = f;
        group.computeIfAbsent(f, x-> new Stack<>()).push(val);
    }
    
    public int pop() {
        int x = group.get(maxFreq).pop();
        freq.put(x, freq.get(x) - 1);
        if (group.get(maxFreq).size() == 0)
            maxFreq--;
        return x;
    }
}

