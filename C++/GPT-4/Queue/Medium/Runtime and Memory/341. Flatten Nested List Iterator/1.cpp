#include <stack>

class NestedIterator {
public:
    std::stack<NestedInteger> elements;

    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            elements.push(nestedList[i]);
        }
    }
    
    int next() {
        int result = elements.top().getInteger();
        elements.pop();
        return result;
    }
    
    bool hasNext() {
        while (!elements.empty()) {
            NestedInteger top = elements.top();
            if (top.isInteger()) {
                return true;
            }

            elements.pop();
            vector<NestedInteger> &nestedList = top.getList();
            for (int i = nestedList.size() - 1; i >= 0; --i) {
                elements.push(nestedList[i]);
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
