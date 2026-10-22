class StockSpanner {
private:
    stack<pair<int, int>> priceSpanHistory; 
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span{1};
        while(!priceSpanHistory.empty() && priceSpanHistory.top().first <= price) {
            span += priceSpanHistory.top().second;
            priceSpanHistory.pop();
        }
        priceSpanHistory.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */