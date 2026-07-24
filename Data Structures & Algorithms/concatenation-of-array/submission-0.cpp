class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int num_len = nums.size();

        for(int i = 0; i < num_len; i++) {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};