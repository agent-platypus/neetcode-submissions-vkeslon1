class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left{0};

        int right = nums.size() - 1;
    
        // 1  0   1   1   1
        // ^      ^       ^ 


        while(left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[left] < nums[mid]) { 
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                }

                else {
                    left = mid + 1;
                }
            }

            else if (nums[left] > nums[mid]) { 
                if (target < nums[right] && target >= nums[mid]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            else {  // if mid == right, there is ambiguity so linear increment the right space until
            // some binary search can be used or the search is effecitvely linear 
                ++left;
            }
        }

        return false;
    }
};