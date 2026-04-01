class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        int num_length = nums.size() - 1;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = num_length;
            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) {
                    k--;
                }
                else if (sum < 0) {
                    j++;
                }

                else {
                    while (j < k && nums[j] == nums[j+1]) j++;
                    while (j < k && nums[k] == nums[k-1]) k--;
                    res.push_back( { nums[i], nums[j], nums[k] } );
                    j++;
                    k--;
                }
            }
        }

        // for(int i = 0; i < num_length; i++) {
        //     int a = nums[i];
        //     unordered_map<int, int> pairs;
        //     for(int j = 0; j < num_length; j++) {
        //         if (j == i) 
        //             continue;
        //         // 0 = a + b + c
        //         // c = -(a+b)

        //         int c = -(nums[j] + a);
        //         if ( pairs.find(c) == pairs.end() ) {
        //             pairs[c] = j;
        //         }
        //         else {
        //             res.push_back( {a, nums[j], c} );
        //         }
        //     }
        // }


        return res; 
    }
};
