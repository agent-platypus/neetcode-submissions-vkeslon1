class MinStack {
private:
    stack<int> dataStack;
    stack<int> minHistory;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        dataStack.push(val);

        if (minHistory.empty() || minHistory.top() > val) {
            minHistory.push(val);
        }
        else {
            minHistory.push(minHistory.top());
        }
    }
    
    void pop() {
        if (!dataStack.empty()) {
            dataStack.pop();
        }

        if (!minHistory.empty()) {
            minHistory.pop();
        }
    }
    
    int top() {
        return dataStack.top();
    }
    
    int getMin() {
        return minHistory.top();
    }
};
