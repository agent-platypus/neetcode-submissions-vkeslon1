class MyCircularQueue {
    vector<int> m_cQueue; 
    int m_size;
    int m_front;
public:
    MyCircularQueue(int k):m_cQueue(k, -1), m_front{}, m_size{} {
        
    }
    
    bool enQueue(int value) {
        if (m_size == m_cQueue.capacity()) {
            return false;
        }
        int rear = (m_front + m_size) % m_cQueue.capacity();
        m_cQueue[rear] = value;
        ++m_size;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        m_cQueue[m_front] = -1;
        m_front = (m_front + 1) % m_cQueue.capacity();
        --m_size;
        return true;
    }
    
    int Front() {
        if (m_size == 0) {
            return -1;
        }
        else {
            return m_cQueue[m_front];
        }
    }
    
    int Rear() {
        if (m_size == 0) {
            return -1;
        }
        else {
            int rear = (m_front + m_size - 1) % m_cQueue.capacity();
            return m_cQueue[rear]; 
        }
    }
    
    bool isEmpty() {
        return m_size == 0;
    }
    
    bool isFull() {
        return !isEmpty();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */