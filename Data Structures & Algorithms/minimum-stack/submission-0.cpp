class Node {
public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = nullptr;
    }        
};

//  node <- node <- node
// bottom          top
class MinStack {
private:
    Node* top_of_stack;
public:
    MinStack() {
        top_of_stack = nullptr;
    }
    
    void push(int val) {
        Node* temp = new Node(val);
        temp->next = top_of_stack;
        top_of_stack = temp;
    }
    
    void pop() {
        if(top_of_stack == nullptr) {
            cout << "Empty stack, nothing to pop" << endl;
            return;
        }

        Node* temp = top_of_stack;
        top_of_stack = top_of_stack->next;

        delete temp;
    }
    
    int top() {
        return top_of_stack->val;
    }
    
    int getMin() {
        Node* temp = top_of_stack;
        int minVal = top_of_stack->val;
        temp = temp->next;
        while(temp != nullptr) {
            minVal = min(minVal, temp->val);
            temp = temp->next;
        }
        return minVal;
    }
};

