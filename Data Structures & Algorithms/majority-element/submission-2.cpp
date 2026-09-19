class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int majority{static_cast<int>(nums.size()) >> 1};
        int curr{nums.front()};
        int cnt{1};
        for(int i = 1; i < nums.size(); ++i) {
            if (cnt > majority) {
                return curr;
            }
            if (nums[i] != curr) {
                curr = nums[i];
                cnt = 1;
                continue;
            }
            ++cnt;
        }
        return curr;
    }
};