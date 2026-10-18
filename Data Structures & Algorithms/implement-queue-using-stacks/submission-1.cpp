class MyQueue {
    stack<int> s1;  // use as original data orde
    stack<int> s2;  // use to reverse data 
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if (empty() || s2.empty()) { // start of a fresh MyQueue container
            s1.push(x);
        }
        else {
            while(!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
            s1.push(x);
        }
    }
    
    // if s1 is not empty(), then s2 is empty and the original order of the elements is preserved 

    // if s1 is empty(), then there was a pop or peek operation and the order of the elements had to be reversed 

    // checking if either stack is empty or not somewhat amortizes the time complexity 

    // lets say a lot of push operations and then a handle of peek/pop operations 

    // amortized o(1)

    // but if there is an even amount of  push and pop/peek operations, time complexity 
    // leans towards O(n) since the stack element order must be reversed 

    // if there are a lot of peek operations then amortized O(1) 


    int pop() { // front element access

        int frontElem;
        if (empty()) {  //empty myQueue 
            frontElem = -1;
        }
        else if (s1.empty()) { // then the container was peeked/popped from previously
            frontElem = s2.top();
            s2.pop();
        }
        else {  // the elements are in their original order
                // need to reverse the order to have the front element at the
                // top of the s2 stack
            while(s1.size() > 1) {
                s2.push(s1.top());
                s1.pop();
            }
            frontElem = s1.top();
            s1.pop();
        }
        return frontElem;
    }
    
    int peek() {
        int frontElem;
        if (empty()) {  //empty myQueue 
            frontElem = -1;
        }
        else if (s1.empty()) { // then the container was peeked/popped from previously
            frontElem = s2.top();
        }
        else {  // the elements are in their original order
                // need to reverse the order to have the front element at the
                // top of the s2 stack
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            frontElem = s2.top();
            
        }
        return frontElem;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
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