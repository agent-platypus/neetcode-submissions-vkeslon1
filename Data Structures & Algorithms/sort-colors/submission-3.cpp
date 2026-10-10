class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        array<int, 3> freq{};

        for(int x: nums) {
            freq[x]++;
        }

        int idx{};
        for(int i{}; i < 3; ++i) {
            while(freq[i]-- > 0) {
                nums[idx] = i;
                ++idx;
            }
        }

    }
};