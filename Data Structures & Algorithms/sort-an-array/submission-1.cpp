class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
    
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        
        if (l < r) {
            int mid = l + (r - l) / 2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid + 1, r);
            merge(nums, l, mid, r);
        }
        

    }

    void merge(vector<int>& nums, int l, int mid, int r) {
        int l_range{mid - l + 1};
        int r_range{r - mid};
        
        int* l_arr = new int[l_range];
        int* r_arr = new int[r_range];

        for(int i = 0; i < (l_range); ++i) {
            l_arr[i] = nums[i + l];
        }
        for(int j = 0; j < (r_range); ++j) {
            r_arr[j] = nums[j + mid + 1];
        }

        int i{};
        int j{};

        int nums_ptr = l;
        while(i < l_range && j < r_range) {
            if (l_arr[i] < r_arr[j]) {
                nums[l] = l_arr[i];
                ++i;
                ++l;
            }
            else {
                nums[l] = r_arr[j];
                ++j;
                ++l;
            }
        }

        while (i < l_range) {
            nums[l++] = l_arr[i++];
        }

        while (j < r_range) {
            nums[l++] = r_arr[j++];
        }

        delete[] r_arr;
        delete[] l_arr;
    } 
};