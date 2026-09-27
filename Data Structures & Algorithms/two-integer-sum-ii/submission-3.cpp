class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left{};
        int right = numbers.size() -1;
        while(left < right) {
            int curr_sum{numbers[left] + numbers[right]};
            if (curr_sum == target) {
                return {left+1,right+1};
            }
            else if (curr_sum > target) {
                --right;
            }
            else {
                ++left;
            }
        }

        return {};
    }
};
