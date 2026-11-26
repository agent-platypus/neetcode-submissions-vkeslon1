class Solution {
public:

    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> curr;

        sort(candidates.begin(), candidates.end());
        dfs(candidates, curr, 0, target);
        return res;
    }

    void dfs(span<const int> nums, vector<int>& curr, int index, int target) {

        if (target == 0) {

            res.push_back(curr);
            return;
        }
        if (index >= nums.size() || target < 0) {
            return;
        }   

        

        curr.push_back(nums[index]);
        dfs(nums, curr, index + 1, target - nums[index]);
        curr.pop_back();
        while(index + 1 < nums.size() && (nums[index] == nums[index + 1] )) {
            ++index;
        }
        dfs(nums, curr, index + 1, target);

    }
};
