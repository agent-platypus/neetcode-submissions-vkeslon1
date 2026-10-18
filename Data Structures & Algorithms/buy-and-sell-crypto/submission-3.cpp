class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //choose no transactions -> profit = 0;
        // then if the current window is < 0, we move left pointer
        int buyIdx{0};

        int maxProfit{};
        for(int currDay{1}; currDay < prices.size(); ++currDay) {\
            int currProfit = prices[currDay] - prices[buyIdx];
            if ( currProfit < 0 ) {
                buyIdx = currDay;
            }
            maxProfit = max(maxProfit, currProfit);
        }
        return maxProfit;
    }
};
