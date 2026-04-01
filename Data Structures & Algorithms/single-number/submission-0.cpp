class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int curr_num = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            curr_num ^= nums[i];
        }

        return curr_num;
    }
};
