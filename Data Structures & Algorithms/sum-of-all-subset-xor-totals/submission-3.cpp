class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int xorTotal{};
        int currXOR{};

        dfs(nums, 0, currXOR, xorTotal);
        return xorTotal;
    }

    void dfs(span<int> nums, int index, int& currXOR, int& xorTotal) {
        if (index >= nums.size()) {
            xorTotal += currXOR;
            return;
        }

        currXOR ^= nums[index];
        dfs(nums, index + 1, currXOR, xorTotal);
        currXOR ^= nums[index];
        dfs(nums, index + 1, currXOR, xorTotal);
    }
};