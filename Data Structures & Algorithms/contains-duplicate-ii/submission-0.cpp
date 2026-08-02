class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> curr;

        int sz_arr = nums.size();

        for(int i = 0; i < sz_arr; i++) {
            auto it = curr.find(nums[i]);
            if (it != curr.end()) {
                if ( (i - it->second) <= k) {
                    return true;
                }
            }
            curr[nums[i]] = i;
        }

        return false;
    }
};