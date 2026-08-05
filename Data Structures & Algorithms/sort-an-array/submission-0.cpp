class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        if(nums.size() < 2) {
            return nums;
        }
        
        quickSort(nums, 0, nums.size() - 1);

        return nums;
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivot = HoarePartition(arr, low, high);
            
            quickSort(arr, low, pivot);
            quickSort(arr, pivot + 1, high);
        }
    }

    int HoarePartition(vector<int>& arr, int low, int high) {
        // code here
        int pivot = arr[low];
        
        int left = low - 1;
        int right = high + 1;
        
        while(1) {
            do {
                left++;
            } while(arr[left] < pivot);
            
            do {
                right--;
            } while(arr[right] > pivot);
            
            if (left >= right) {
                return right;
            }
            
            swap(arr[left], arr[right]);
        
        }
        
    }
};