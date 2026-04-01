class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;


        // in a non rotated sorted array, the min value is at the very left
        // searching for a value in a non rotated array 
        // left right and mid
        // if value > nums[mid] then move left to mid + 1
        // if value <  nums[mid] move right to mid - 1
        // if value =  nums[mid], return index of mid


        // so every value on the right SHOULD be greater than those on the left
        // 
        // 
        // 0 1 2 3 4   //  0 1 2 3 4 5 

        // 1 2 3 4 0   //  1 2 3 4 5 0

        // 2 3 4 0 1   //  2 3 4 5 0 1 

        // 3 4 0 1 2   //  3 4 5 0 1 2 

        // 4 0 1 2 3   //  4 5 0 1 2 3

                       //  5 0 1 2 3 4

        // if the array is not rotated, then
        if (nums[left] < nums[right] || !nums.size() ) {
            return nums[left];
        }

        while(left < right) {
            mid = (left + right) / 2;
            if( nums[mid] > nums[right]) {  // if nums[mid] > nums[right] then the minimum lies in the right side
                // if ( nums[right] < nums[left]) {
                //     left = mid + 1;
                //     continue;
                // }

                left = mid + 1;
                continue;
            }
            // [4,5,0,1,2,3] 

            else if( nums[mid] < nums[right] ) {  // if nums[mid] < nums[right] then the minimum lies in the left side or middle
                // if(nums[right] < nums[left]) {
                //     right = mid - 1;
                //     continue;
                // }   
                    right = mid;
                    continue;
            }
        }

        return nums[left];

    }
};
