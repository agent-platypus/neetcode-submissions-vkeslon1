class Solution {
public:

    vector<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        dfs(nums, curr, 0);
        return res;
    }

    void dfs(span<const int> nums, vector<int> currSubset, int index) {
        if (index >= nums.size()) {
            res.push_back(currSubset);
            return;
        }
        
        currSubset.push_back(nums[index]);
        dfs(nums, currSubset, index + 1);
        currSubset.pop_back();
        while(index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            ++index;
        }
        dfs(nums, currSubset, index + 1);
    }
};
