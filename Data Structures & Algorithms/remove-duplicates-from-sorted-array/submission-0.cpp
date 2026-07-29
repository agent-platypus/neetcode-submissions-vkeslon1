class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int right = 1;
        int currNum = nums[0];

        while(right < nums.size()) {
            if (nums[right] == currNum) {
                nums.erase(nums.begin() + right);
                continue;
            }
            else {
                currNum = nums[right];
                right++;
            }
        }

        return nums.size();
    }
};