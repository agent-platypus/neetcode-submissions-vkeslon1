class StockSpanner {
private:
    vector<short int> priceHistory;
    size_t numElements;
public:
    StockSpanner() {
        priceHistory.reserve(10000);
        numElements = 0;
    }
    
    int next(int price) {
        
        

        if (priceHistory.empty() || priceHistory.back() > price) {
            priceHistory.push_back(price);
            ++numElements;
            return 1;
        }
        int span{1};

        int idx = numElements - 1;

        while(idx >= 0 && priceHistory[idx] <= price) {     
            ++span;
            --idx;
        }
        priceHistory.push_back(price);
        ++numElements;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */