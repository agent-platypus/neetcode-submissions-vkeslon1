class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = 100001;
        int sum = 0;
        int left = 0; 

        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            if (sum >= target) {
                if (right == 0) {
                    min_len = 1;
                    return 1;
                }
                min_len = min(min_len, right - left + 1);
            

                while(sum >= target) {
                    sum -= nums[left];
                    left++;
                }

                cout << left;
                cout << right;
                // when the loop exits, the subarray range of decr sum of the last iteration of the loop
                // is the smallest subarray length
                min_len = min(min_len, right - (left - 1) + 1);
            }
        }



        if (min_len == 100001) 
            return 0;
        else 
            return min_len;
    }
};