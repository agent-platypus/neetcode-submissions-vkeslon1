class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {
        
    }
    
    void push(int x) {

        if (q1.empty()) {
            if (q2.empty()) {
                q1.push(x);
            }
            else {
                q2.push(x);
            }
        }
        else {
            q1.push(x);
        }
    }
    
    int pop() {
        int popped_elem;
        if (q1.empty()) {
            popped_elem = pop_helper(q2, q1);
        }
        else {
            popped_elem = pop_helper(q1, q2);
        }

        return popped_elem;
    }
    
    int pop_helper(queue<int>& a, queue<int>& b) {
        while(!a.empty()) {
            if (a.size() == 1) {
                break;
            }
            b.push(a.front());
            a.pop();
        }
        int popped_elem = a.front();
        a.pop();
        return popped_elem;
    }

    int top() {
        if (q1.empty()) {
            return q2.back();
        }
        else 
            return q1.back();
    }
    
    bool empty() {
        return q1.empty() && q2.empty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */