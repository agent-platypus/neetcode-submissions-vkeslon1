class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        int mid; 
        while(left < right) {
            mid = (left + right) / 2; 
            if(nums[left] < nums[right]) {
                return nums[left];
            }
            else { //nums[left] > nums[right]
                if(nums[mid] < nums[left]) { // min is on the left side
                    right = mid;
                }

                else { // nums[mid] > nums[left]  min is on right side
                    left = mid + 1;
                }
            }
            

        }

        return nums[left];
    }
};
