class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pairs;  
        for( int i = 0; i < nums.size(); i++ ) {    
            auto it = pairs.find(target - nums[i]);
            if ( it != pairs.end() ) {
                return {it->second, i};
            }
            pairs[nums[i]] = i;
        }

        return {0};
    }
};
