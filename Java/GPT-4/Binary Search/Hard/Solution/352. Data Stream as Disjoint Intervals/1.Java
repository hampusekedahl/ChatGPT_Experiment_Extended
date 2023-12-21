import java.util.*;

class SummaryRanges {
    private TreeMap<Integer, int[]> tree;

    public SummaryRanges() {
        tree = new TreeMap<>();
    }
    
    public void addNum(int val) {
        if (tree.containsKey(val)) {
            return;
        }
        
        Integer l = tree.lowerKey(val);
        Integer h = tree.higherKey(val);
        
        if (l != null && h != null && tree.get(l)[1] + 1 == val && h == val + 1) {
            tree.get(l)[1] = tree.get(h)[1];
            tree.remove(h);
        } else if (l != null && tree.get(l)[0] <= val && tree.get(l)[1] >= val) {
            return;
        } else if (l != null && tree.get(l)[1] + 1 >= val) {
            tree.get(l)[1] = val;
        } else if (h != null && h == val + 1) {
            tree.put(val, new int[]{val, tree.get(h)[1]});
            tree.remove(h);
        } else {
            tree.put(val, new int[]{val, val});
        }
    }
    
    public int[][] getIntervals() {
        return tree.values().toArray(new int[tree.size()][]);
    }
}
