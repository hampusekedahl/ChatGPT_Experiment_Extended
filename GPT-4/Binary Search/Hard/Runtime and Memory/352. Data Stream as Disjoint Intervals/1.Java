import java.util.*;

class SummaryRanges {
    private TreeMap<Integer, int[]> tree;

    public SummaryRanges() {
        tree = new TreeMap<>();
    }
    
    public void addNum(int value) {
        if (tree.containsKey(value))
            return;
        
        Integer lowerKey = tree.lowerKey(value);
        Integer higherKey = tree.higherKey(value);
        
        if (lowerKey != null && higherKey != null && tree.get(lowerKey)[1] + 1 == value && higherKey == value + 1) {
            tree.get(lowerKey)[1] = tree.get(higherKey)[1];
            tree.remove(higherKey);
        } else if (lowerKey != null && tree.get(lowerKey)[1] + 1 >= value) {
            tree.get(lowerKey)[1] = Math.max(tree.get(lowerKey)[1], value);
        } else if (higherKey != null && higherKey == value + 1) {
            tree.put(value, new int[]{value, tree.get(higherKey)[1]});
            tree.remove(higherKey);
        } else {
            tree.put(value, new int[]{value, value});
        }
    }
    
    public int[][] getIntervals() {
        return tree.values().toArray(new int[tree.size()][]);
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(value);
 * int[][] param_2 = obj.getIntervals();
 */
