class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 2) {
            return nums.size();
        }

        int left{0};
        int right{1};
        int maxLen{};
        int currConsLen{1};

        int checkVal{nums[left] + 1};
        while(right < nums.size()) {
            // if the current element is a duplicate but the sequence is still valid, continue
            if (nums[right] == (checkVal)) {
                ++right;
                ++currConsLen;
                ++checkVal;
            }
            else if (nums[right] == nums[right - 1]) {
                ++right;
            }
            else { // if the nums[right] is not a duplicate of the left adjacent and since the array is sorted
                    // and if nums[right] != nums[left] + 1 
                maxLen = max(maxLen, currConsLen);
                left = right;
                checkVal = nums[right] + 1;
                currConsLen = 1;
                ++right;
            }
            // if the current elem value invalidates the current sequence as non consecutive then 
            // update maxLen and adjust the left pointer to right pointer's position 

        }

        return max(maxLen, currConsLen);
        
    }
};


// 2    3   4    4   5  10   20
// l             r   r  r
//                      l

// 0  1  1  2  3  4  5  6 
