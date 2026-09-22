class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        

        int counter{};
        remove_if(nums.begin(), nums.end(), [&counter, val](int elem) { 
            if (elem == val) {
                return true;
            }
            ++counter;
            return false;
        });
        return counter;

        
    }
};