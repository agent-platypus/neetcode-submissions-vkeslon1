class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            num ^= nums[i];
        }

        for(int i = 0; i < nums.size() + 1; i++) {
            num ^= i;
        }

        cout << num << endl;

        return num;
    }
};
