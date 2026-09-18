class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> freq;
        for(int i{}; const auto& x: nums) {
            if (freq.find(target - x) != freq.end()) {
                return {freq[target-x], i};
            }
            freq[x] = {i};
            ++i;
        }

    }
};
