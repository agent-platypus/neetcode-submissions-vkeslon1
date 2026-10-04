class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // int stack_arr[20000];

        // copy(nums.begin(), nums.end(), stack_arr);

        int numValidSubarr{};
        int currSum = 0;
        unordered_map<int, int> prefixSums;
        prefixSums[0] = 1;

        for(const auto& x: nums) {

        // for(int i{}; i < nums.size(); ++i) {
            // currSum += stack_arr[i];
            currSum += x;
            int diff = currSum - k;
            numValidSubarr += prefixSums[diff];
            prefixSums[currSum]++;
        }

        return numValidSubarr;
    }
};