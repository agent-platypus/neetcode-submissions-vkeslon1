class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();

        int i = 0;
        while(i < nums.size()) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
                k--;
                continue;
            }
            i++;
        }
        return k;
    }
};