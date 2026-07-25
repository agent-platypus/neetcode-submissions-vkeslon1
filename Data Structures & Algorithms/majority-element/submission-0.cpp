class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int left = 0;
        int mfreqelem = 0;
        int maxfreq = 0;

        for(int right = 0; right < nums.size(); right++) {
            if (nums[right] != nums[left]) {
                left = right;
            }

            int currfreq = right - left + 1;
            maxfreq = max(maxfreq, currfreq);

            if (currfreq >= maxfreq) {
                mfreqelem = nums[left];
            }
        }

        return mfreqelem;
    }
};