#include <print>

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left{*max_element(weights.begin(), weights.end())};

        int right{};

        for_each(weights.begin(), weights.end(), [&](int currWeight) {right += currWeight;
        });

        // each ship must be able to carry at least the heaviest package

        // the least amount of days possible is 1 day to ship all packages which means the ship
        // capacity needs to be the sum of the whole array

        vector<int> validWeights;

        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            
            int daysForCarryingCap{numDays(weights, mid)};

            print("Ship carrying capacity = {}\nDays to ship packages = {}\n", mid, daysForCarryingCap);
            if (daysForCarryingCap <= days) {
                validWeights.push_back(mid);
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        // for_each(validWeights.begin(), validWeights.end(), [](int validweight) {
        //     print("valid weight = {}\n", validweight);
        // });
        return *min_element(validWeights.begin(), validWeights.end());

        
    }

    int numDays(span<const int> weights, int carryingCapacity) {
        int days{1};
        int currWeight{};
        for(int i{}; i < weights.size(); ++i) {
            currWeight += weights[i];

            if (currWeight > carryingCapacity) {
                ++days;
                currWeight = weights[i];
            }
        }

        // print("Num days = {}\n", days);
        return days;

    }
};