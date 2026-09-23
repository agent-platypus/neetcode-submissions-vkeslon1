class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i{}; i < nums.size(); ++i) {
            if (nums[i] > 0) 
                break;
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;

            int left{i + 1};
            int right = nums.size() - 1;
            while(left < right) {
                int curr_sum{nums[i] + nums[left] + nums[right]};
                if (curr_sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    while(left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                }
                else if (curr_sum > 0) {
                    --right;
                }
                else {
                    ++left;
                }

            }
        }
        return res;
    }
};


