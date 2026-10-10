#include <print>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixProd(n, 0);
        vector<int> postfixProd(prefixProd);
        prefixProd[0] = nums[0];
        postfixProd[n - 1] = nums[n - 1];
        for(int i{1}, j{n-2}; i < n && j >= 0; ++i, --j) {
            prefixProd[i] = prefixProd[i - 1] * nums[i];
            postfixProd[j] = postfixProd[j + 1] * nums[j];
        }

        nums[0] = postfixProd[1];
        nums[n - 1] = prefixProd[n - 2];
        for(int i{1}; i < n - 1; ++i) {
            nums[i] = prefixProd[i - 1] * postfixProd[i + 1];
        }
        

        return nums;
        // assuming i not 0 and not nums.size() - 1
        //prefixSum[i  - 1] * postfixSum[i + 1]
    }
};
