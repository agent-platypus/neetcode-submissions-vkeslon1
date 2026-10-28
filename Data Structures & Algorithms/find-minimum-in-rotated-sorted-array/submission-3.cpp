#include <print>

class Solution {
public:
    int findMin(vector<int> &nums) {
// print("current indices\n");
//             print("left = {}, mid = {}, right = {}\n",  left, mid, right);

        // hypothesis: for the subarray in the current window, some partition exists within the window such that
        // in that partition's left to right range, it is sorted and we can either eliminate that partition or move into that
        // partition for the search of the min element 
        

        // 1234567  -> left < right so we know that the range is sorted and can simply move the right to mid and converge to 
        // the minimum element
 
        // for all of these subarrays nums[left] > nums[right]

        // left > right
        // mid = (right - left) / 2 

        // 2345671 -> mid > left, the left side from left -> mid is sorted 
        // 3456712    left = mid + 1
        // 4567123

        // 5671234 -> mid < left, the right side from mid -> right is sorted
        //          // right = mid
        // 6712345
        // 7123456
        // but the element at mid could be the minimum 
        int left{};
        int right = nums.size() - 1;
        int mid;

        int minElem{999900};
        while(left <= right) {
            
            if (nums[left] < nums[right]) {
                minElem = min(minElem, nums[left]);
                break;
            }
            // we only enter this while loop if nums[left] > nums[right]
            mid = left + ((right - left) >> 1);

            minElem = min(minElem, nums[mid]);

            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return minElem;

    }
};
