#include <print>

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int left{};
        int right = nums.size() - 1;
        int i{};

        while (i <= right) {
            if (nums[i] == 0) {
                swapInt(nums[i], nums[left]);
                ++left;
            }
            else if (nums[i] == 2) {
                swapInt(nums[i], nums[right]);
                --right;
                --i;
                
            }
            ++i;
        }

    }

    void swapInt(int& a, int& b) {
        if (a == b) {
            return;
        }
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};