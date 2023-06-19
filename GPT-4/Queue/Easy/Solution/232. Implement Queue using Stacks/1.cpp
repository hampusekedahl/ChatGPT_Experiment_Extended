#include <stack>

class MyQueue {
public:
    std::stack<int> stack1, stack2;

    MyQueue() {
        
    }
    
    void push(int x) {
        // Push element x to the back of the queue by pushing it to the first stack.
        stack1.push(x);
    }
    
    int pop() {
        // Check if the second stack is empty. If so, transfer elements from the first stack.
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // Remove and return the element from the front of the queue.
        int frontElement = stack2.top();
        stack2.pop();
        return frontElement;
    }
    
    int peek() {
        // Check if the second stack is empty. If so, transfer elements from the first stack.
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // Return the element at the front of the queue.
        return stack2.top();
    }
    
    bool empty() {
        // Return true if both stacks are empty, false otherwise.
        return stack1.empty() && stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
