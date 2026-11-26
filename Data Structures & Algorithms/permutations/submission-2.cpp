class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm;
        int bitField{};

        dfs(nums, perm, bitField);
        return res;
    }

    void dfs(span<const int> nums, vector<int>& perm, int& bitField) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        for(int i{}; i < nums.size(); ++i) {
            int currBit = bitField & (1 << i);

            if (!currBit) {
                perm.push_back(nums[i]);
                bitField |= (1 << i);
                dfs(nums, perm, bitField);
                perm.pop_back();
                bitField &= ~(1 << i);
            }
        }
    }
};
