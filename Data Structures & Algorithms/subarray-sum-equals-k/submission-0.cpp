class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        int currsum = 0;
        int res = 0;
        prefixSum[0] = 1;

        for(int num: nums) {
            currsum += num;
            int diff = currsum - k;
            res += prefixSum[diff];
            prefixSum[currsum]++;
        }

        return res;
        
    }
};