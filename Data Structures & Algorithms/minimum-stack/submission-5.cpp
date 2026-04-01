class MinStack {
private:
    std::stack<int> stack;
    std::stack<int> minStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        stack.push(val);
        int newMin;
        if ( minStack.empty() ) {
            newMin = val;
        } 
        else {
            newMin = minStack.top();
        }

        minStack.push(min(val, newMin));   
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
