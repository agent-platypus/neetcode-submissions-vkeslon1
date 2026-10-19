#include <algorithm>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin() + (k));

        reverse(nums.begin() + k, nums.begin() + size);
    }

    // void reverse(vector<int>& nums, int start, int end) {
    //     while(start < end) {
    //         swap(nums[start], nums[end]);
    //         ++start;
    //         --end;
    //     }
    // }
};