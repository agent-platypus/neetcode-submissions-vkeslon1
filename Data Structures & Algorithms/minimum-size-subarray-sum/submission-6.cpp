#include <print>

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int sum{};
        int left{};
        int right{};

//   7
//         2 3 1 2 4 3 
// right             ^
// left            ^

// sum      7
// minLen   2
        int minLen = numeric_limits<int>::max();

        while(right < nums.size()) {
            sum += nums[right];
            while (sum >= target && left <= right) {
                // print("left = {}, right = {}, valid window Len = {}\n", left, right, right - left + 1);
                // print("curr sum = {}\n", sum);
                minLen = min(minLen, right - left + 1);
                
                sum -= nums[left];
                ++left;
                // print("new window sum = {}\n", sum);
            }
            ++right;
        }

        if (minLen == numeric_limits<int>::max()) {
            return 0;
        }

        return minLen;
    }
};