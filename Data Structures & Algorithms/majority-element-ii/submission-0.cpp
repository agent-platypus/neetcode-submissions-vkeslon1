class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> freq;
        int n_div = nums.size() / 3;
        vector<int> res;


        for(int x: nums) {
            freq[x]++;
        }

        for(auto it: freq) {
            if (it.second > n_div) {
                res.push_back(it.first);
            }
        }

        return res;
    }
};