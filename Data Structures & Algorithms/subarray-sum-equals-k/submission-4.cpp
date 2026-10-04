class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int numValidSubarr{};
        int currSum = 0;
        unordered_map<int, int> prefixSums;
        prefixSums[0] = 1;

        for(const auto& x: nums) {
            currSum += x;
            int diff = currSum - k;
            numValidSubarr += prefixSums[diff];
            prefixSums[currSum]++;
        }

        return numValidSubarr;
    }
};