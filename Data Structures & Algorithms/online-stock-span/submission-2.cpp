class StockSpanner {
private:
    stack<int> priceHistory;
    stack<int> nextTempStack;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if (priceHistory.empty() || priceHistory.top() > price) {
            priceHistory.push(price);
            return 1;
        }

        int span{1};
        while(!priceHistory.empty() && priceHistory.top() <= price) {
            nextTempStack.push(priceHistory.top());
            priceHistory.pop();
            ++span;
        }

        while(!nextTempStack.empty()) {
            priceHistory.push(nextTempStack.top());
            nextTempStack.pop();
        }

        priceHistory.push(price);
        return span;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */