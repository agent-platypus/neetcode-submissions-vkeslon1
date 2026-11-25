class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int numSubset = 1 << (nums.size());

        // the number of subsets in the input array is 2^ (number of elements) 

        // number of binary representations is 2^3 -> number of subsets

        // how to correspond a bit position 
        vector<vector<int>> res;

        for(int i{}; i < numSubset; ++i) {
            vector<int> subset;
            subset.reserve(nums.size());
            // for some outer loop index i, we shift i to the right by the j 
            // extract the LSB and then if the LSB is set, then the jth element in the 
            // input array is pushed to the current subset 

            // lets say i = 3 -> 0b011
            // for j = 0 -> mask 011 & 001 -> true so nums[0] is pushed ot the current subset
            // j = 1 -> mask (011 >> 1) & 001 -> 001 & 001 -> true so nums[1] pushed

            // j = 2, result is false so nums[2] not added

            // 011 

            // 100
            for(int j{}; j < nums.size(); ++j) { // building the subset
                int jthElemInc = (i >> j) & 0x1;
                if (jthElemInc) {
                    subset.push_back(nums[j]);
                }
            }
            res.push_back(subset);
        }

        return res;

    }
};
