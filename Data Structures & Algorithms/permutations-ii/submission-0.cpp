class Solution {
public:

    set<vector<int>> res;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> curr;
        int bitField{};

        sort(nums.begin(), nums.end());
        dfs(nums, curr, bitField);
        return vector<vector<int>>(res.begin(), res.end());
    }

    void dfs(span<const int> nums, vector<int>& curr, int& bitField) {
        if (curr.size() == nums.size()) {
            res.insert(curr);
            return;
        }

        for(int i{}; i < nums.size(); ++i) {
            int currBit = bitField & (1 << i); 
            if (!currBit) {
                curr.push_back(nums[i]);
                bitField |= (1 << i);
                dfs(nums, curr, bitField);
                curr.pop_back();
                bitField &= ~(1 << i);
            }
        }
        
    
    }
};

