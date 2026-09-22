class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int left{};
        int unique_elem{nums.front()};
        for(int i{1}; i < nums.size(); ++i) {

            if (nums[i] != unique_elem) {
                nums[left + 1] = nums[i];
                ++left;
                unique_elem = nums[i];
            }

        }
        return ++left;
    }
};

// 1   1   1  2   2  3   3  4 

// lp         i

//  1   2  1  2  2   3
//     lp         i   i

//   1  2  3  2  2  3  4
//           lp

///  1  2   3  4 


// lp   i
// 1  1   2
// lp  i
// 1  2 
// lp i

