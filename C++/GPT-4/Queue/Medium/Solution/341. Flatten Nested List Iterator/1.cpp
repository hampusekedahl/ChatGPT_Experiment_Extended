#include <vector>
#include <stack>

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation


class NestedIterator {
public:
    std::stack<NestedInteger> nodes;

    NestedIterator(std::vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            nodes.push(nestedList[i]);
        }
    }
    
    int next() {
        int result = nodes.top().getInteger();
        nodes.pop();
        return result;
    }
    
    bool hasNext() {
        while (!nodes.empty()) {
            NestedInteger current = nodes.top();
            if (current.isInteger()) {
                return true;
            }
            nodes.pop();

            std::vector<NestedInteger> &nestedList = current.getList();
            for (int i = nestedList.size() - 1; i >= 0; --i) {
                nodes.push(nestedList[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
