class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // profit = sellingprice - buyingprice
        int minPrice = 101;
        int bestProfit = 0;
        for(int p : prices) {
            minPrice = min(minPrice, p);
            bestProfit = max(bestProfit, p - minPrice);
        }
        return bestProfit;
    }

};
