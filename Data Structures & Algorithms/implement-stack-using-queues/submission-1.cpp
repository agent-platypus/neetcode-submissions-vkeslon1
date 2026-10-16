class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {

        if (q1.empty() && !q2.empty()) {
            q2.push(x);
        }
        else {
            q1.push(x);
        }
    }
    
    int pop() {
        if (!empty()) {
            queue<int>* nonEmptyQueue;
            queue<int>* emptyQueue;

            if (q1.empty()) {
                nonEmptyQueue = &q2;
                emptyQueue = &q1;
            }
            else {
                nonEmptyQueue = &q1;
                emptyQueue = &q2;
            }

            while(nonEmptyQueue->size() > 1) {
                emptyQueue->push(nonEmptyQueue->front());
                nonEmptyQueue->pop();
            }

            int temp = nonEmptyQueue->front();
            nonEmptyQueue->pop();
            return temp;
        }

        else {
            return -1;
        }

        
    }
    
    int top() {

        if (!empty()) {
            if (!q1.empty()) {
                return q1.back();
            }
            else if (!q2.empty()) {
                return q2.back();
            }
        }

        else {
            return -1;
        }
        
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