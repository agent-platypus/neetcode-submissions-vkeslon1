class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(nums, curr, 0, res, target);
        return res;
    }

    void dfs(span<int> nums, vector<int>& curr, int index, vector<vector<int>>& res, int target) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        if (target < 0 || index >= nums.size()) {
            return;
        }

        curr.push_back(nums[index]);
        dfs(nums, curr, index, res, target - nums[index]);
        curr.pop_back();
        dfs(nums, curr, index + 1, res, target); 
    }
};
