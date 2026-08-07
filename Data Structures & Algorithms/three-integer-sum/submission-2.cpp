class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        int n = nums.size(); 
        if (n < 3) {
            return {};
        }

        int num_length = n - 1;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;
            while(right > left) {
                if (left > (i + 1) && nums[left] == nums[left-1]) {
                    left++;
                    continue;
                }
                if ((right < (n - 1) && nums[right] == nums[right+1])) {
                    right--;
                    continue;
                }

                int sum = nums[left] + nums[right] + nums[i];
                if (sum == 0) {
                    res.push_back({nums[left], nums[right], nums[i]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }

                else if (sum > 0) {
                    right--;
                }
                else {
                    left++;
                }

            }

        }




        return res; 
    }
};
