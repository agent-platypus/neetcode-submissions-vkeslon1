class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> storenums;
        for(int i = 0; i < nums.size(); i++) {
            if(storenums.find(nums[i]) != storenums.end()) {
                return true;
            }
            storenums[nums[i]] = i;
        }
        return false;
    } 
};