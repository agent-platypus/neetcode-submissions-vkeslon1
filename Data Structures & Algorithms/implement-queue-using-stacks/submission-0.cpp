class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if (s1.empty()) {
            while(!s2.empty()) {
                int curr = s2.top();
                s2.pop();
                s1.push(curr);
            }
        }

        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while(!s1.empty()) {
                int curr = s1.top();
                s1.pop();
                s2.push(curr);
            } 
        }
        
        // top of s2 will have the first element
        int front = s2.top();
        s2.pop();
        
        return front;
    }
    
    int peek() {
        if (s2.empty()) {
            while(!s1.empty()) {
                int curr = s1.top();
                s1.pop();
                s2.push(curr);
            }
        }
        
        // top of s2 will have the first element
        int front = s2.top();
        return front;
    }
    
    bool empty() {
        if (s1.empty() && s2.empty()) {
            return true;
        }
        else {
            return false;
        }
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