class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        array<int, 3> freq{};

        for(int x: nums) {
            freq[x]++;
        }

        for(int i{}; i < nums.size(); ++i) {
            if (freq[0] > 0) {
                --freq[0]; 
                nums[i] = 0;
            }
            else if (freq[1] > 0) {
                --freq[1];
                nums[i] = 1;
            }
            else if (freq[2] > 0) {
                --freq[2];
                nums[i] = 2;
            }
            
        }
    }
};