class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> res;
        

        for(const auto& x: nums) {
            freq[x]++;
        }

        for(const auto& x: freq) {
            if (x.second > (nums.size() / 3)) {
                res.push_back(x.first);
            }
        }

        return res;
    }
};