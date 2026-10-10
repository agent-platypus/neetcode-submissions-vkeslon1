class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int right = nums.size() - 1;
        int left = 0;

        int mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);

            if (nums[mid] == target) {
                return mid;
            }

            else if (nums[mid] > target){
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }

        if (target > nums[mid]) {
            return ++mid;
        }
        else {
            return mid;
        }
    }
};