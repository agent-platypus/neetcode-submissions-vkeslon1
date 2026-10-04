class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // initial approach
        // sort the array 
        sort(nums.begin(), nums.end());

        // after sorting, there will be a smallest and largest number in the array
        // the possible values of the sequence would be
        // smallest number = i
        // largest number = n
        // i, i + 1, i + 2, ... , n 
        
        // the actual array vs the sequence will probably not be 1 to 1
        // -3 -1 0 -> want 1

        // 0 3 4 5 6 -> want 1

        // we want to find i + (x) such that it is the smallest positive integer that 
        // would be a part of the sequence in the set of possible values 


        // 1 1 2 3 duplicate
        // 0 1 2 3 equal 
        // -1 0 1 2 less than
        // 1 3 4 greater than
        int missing = 1;
        for(const auto& x: nums) {
            if (x > 0 && x == missing) {
                ++missing;
            }
        }
        return missing;
    }
};