class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        int n = nums.size() - 1;
        for(int i = n; i > 0; --i) {
            if (i < n && nums[i] == nums[i + 1]) {
                continue;
            }

            if (nums[i] < 0) {
                break;
            }
            int right = i - 1;
            int left{};
            while(left < right) {
                int curr_sum{nums[right] + nums[left] + nums[i]};
                if (curr_sum == 0) {
                    res.push_back({nums[right], nums[left], nums[i]});
                    --right;
                    ++left;
                    while(left < right && nums[right] == nums[right + 1]) {
                        --right;
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


