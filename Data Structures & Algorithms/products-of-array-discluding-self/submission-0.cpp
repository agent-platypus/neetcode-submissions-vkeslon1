class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numsize = nums.size();
        int PrefixProducts[numsize];
        int SuffixProducts[numsize];
        vector<int> results;
        // prefix prod
        // prod[0] = nums[0]
        // prod[1] = prod[0] * nums[1]
        // prod[2] = prod[1] * nums[2]
        // etc
        PrefixProducts[0] = nums[0];
        for(int i = 1; i<numsize; i++) {
            PrefixProducts[i] = PrefixProducts[i-1] * nums[i];
        }

        SuffixProducts[numsize-1] = nums[numsize-1];
        for(int i = numsize - 2; i >= 0; i--) {
            SuffixProducts[i] = SuffixProducts[i+1] * nums[i];
        }
        
        results.push_back(SuffixProducts[1]);

        for(int i = 1; i< numsize-1 ; i++) {
            results.push_back(PrefixProducts[i-1] * SuffixProducts[i+1]);
        }

        results.push_back(PrefixProducts[numsize-2]);

        return results;
        // suffix prod
        // prod[size-1] = nums[size - 1]
        // prod[size-1 - 1] = prod[size-1] * nums[size-1 -1]
        // prod[size-1 - 2] = prod[size-2] * nums[size-1 -2]


        // to calculate the nums[3] => prefixProd[2] * suffixProd[4] 



    }
};
