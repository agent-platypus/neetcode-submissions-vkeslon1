class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int numsXORAll{};

        for(int x: nums) {
            numsXORAll ^= x;
        }

        for(int i{}; i <= nums.size(); ++i) {
            numsXORAll ^= i;
        }

        return numsXORAll;
    }
};
