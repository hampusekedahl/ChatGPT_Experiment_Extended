import java.util.Iterator;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;

public class NestedIterator implements Iterator<Integer> {

    private LinkedList<Integer> integers;

    public NestedIterator(List<NestedInteger> nestedList) {
        integers = new LinkedList<>();
        flatten(nestedList);
    }

    @Override
    public Integer next() {
        return integers.poll();
    }

    @Override
    public boolean hasNext() {
        return !integers.isEmpty();
    }
    
    private void flatten(List<NestedInteger> nestedList) {
        for (NestedInteger i : nestedList) {
            if (i.isInteger()) {
                integers.add(i.getInteger());
            } else {
                flatten(i.getList());
            }
        }
    }
}

