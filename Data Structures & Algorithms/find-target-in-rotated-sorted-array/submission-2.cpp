class Solution {
public:
    int search(vector<int>& nums, int target) {
       int left = 0;
       int right = nums.size() - 1;
        int indexMin;

        while(left < right) {
            int mid = (left + right) / 2;
            if( nums[mid] > nums[right]) {  // if nums[mid] > nums[right] then the minimum lies in the right side
                left = mid + 1;
            }
            else {  // if nums[mid] < nums[right] then the minimum lies in the left side or middle 
                right = mid;
            }
        }

        indexMin = left;
        left = 0;
        right = nums.size() - 1;

        if(target >= nums[indexMin] && target <= nums[right]) {
            left = indexMin;
        }
        else {
            right = indexMin;
        }

        while(left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return -1;

    }

};
