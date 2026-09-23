class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int arr[30000];

        copy(nums.begin(), nums.end(), arr);

        int left{1};
        

        for(int i{1}; i < nums.size(); ++i) {

            if (arr[i] != arr[i - 1]) {
                arr[left++] = arr[i];
            }

        }

        copy(arr, arr + left, nums.begin());
        return left;


        // auto it = unique(nums.begin(), nums.end());

        // nums.erase(it, nums.end());
        // return nums.size();
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

