#include <print>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left{};
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = left + ((right - left) >> 1);

            print("left idx = {}, mid idx = {}, right idx = {}, mid element = {}\n", left, mid, right, nums[mid]);
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[right] == target) {
                return right;
            }
            if (nums[left] == target) {
                return left;
            }

            if (nums[mid] > nums[right]) { // we know right side is rotated and left is sorted, and we can determine
            // the range of values of the sorted side to eliminate in the search
                if (target > nums[mid] || target < nums[left]) {
                    // if the target is bigger than the largest number in the sorted portion
                    // or the target is smaller than the smallest number in the sorted portion
                    // the target may exist in the left side
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }

            }
            else {  // right side is sorted 
                if (target > nums[right] || target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }

        }

        return -1;
        
    }
};
