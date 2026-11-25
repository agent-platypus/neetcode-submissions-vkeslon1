class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int numSubsets = 1 << nums.size();

        int totalSum{};
        for(int i{}; i < numSubsets; ++i) {
            int currSubsetXOR{};
            for(int j{}; j < nums.size(); ++j) {
                int elemInc = (i >> j) & 0x1;
                if (elemInc) {
                    currSubsetXOR ^= nums[j];
                }
            }
            totalSum += currSubsetXOR;
        }

        return totalSum;
    }
};