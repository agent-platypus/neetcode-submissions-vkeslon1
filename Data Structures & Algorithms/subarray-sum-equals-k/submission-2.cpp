class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int numValidSubarr{};
        for(int left{}; left < nums.size(); ++left) {
            int currSum = nums[left];
            if (currSum == k) {
                ++numValidSubarr;
            }
            for(int right{left + 1}; right < nums.size(); ++right) {
                currSum += nums[right];
                if (currSum == k) {
                    ++numValidSubarr;
                }
            }
        }
        return numValidSubarr;
    }
};