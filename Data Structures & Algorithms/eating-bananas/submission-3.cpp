class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // k

        // smallest k such that
        // h * k >= sum of piles

        // 1 4 3 2  9
        
        // 1 2 3 4   4  k -> 4
        //           5  k -> 2
        //           6  k -> 2
        //           7  


        // 4 10 23 25   4  k->25
        //              5  k->23 
        //              6  k->13
        
        // range of possible numbers for the min k is [1, max(piles)] 

        // 1. look for the max
        // 2. binary search on the range from 1 to the max
        // 3. 

        // int left{};
        // int right{greatest};

        // to check if the current mid/banana eating rate is valid 
        // iterate through the input piles and increment some hour counter

        // // 
        // 1 13 5 9   h = 6  k = 7

        // 1 2 3 4 5 6 7 8 9 10 11 12 13
        // L           M               R
        // ^           ^               ^

        
        int left{1};
        int right = *max_element(piles.begin(), piles.end());

        vector<int> validK; 
        while(left <= right) {
            int mid = left + ((right - left) >> 1);

            long long hoursForCurrK = numHours(piles, mid);
            if (hoursForCurrK <= h) {
                validK.push_back(mid);
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return *min_element(validK.begin(), validK.end());

    }

    long long numHours(span<const int> pilesInput, int k) {
            long long counter = 0;
            for(int x: pilesInput) {
                counter += (x / k);
                if (x % k != 0) {
                    ++counter;
                }
            }

            return counter;
    }
};
