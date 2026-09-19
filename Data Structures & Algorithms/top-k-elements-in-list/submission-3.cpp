class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> elem_freq;
        sort(nums.begin(), nums.end());

        for(const auto& x: nums) {
            elem_freq[x]++;
        }


        vector<pair<int,int>> freq;

        for(auto it: elem_freq) {
            freq.push_back({it.second, it.first});
        }


        sort(freq.rbegin(), freq.rend());
        // , [](auto a, auto b) {
        //     return a.second > b.second;
        // });

        vector<int> res;
        for(int i{}; i < k; ++i) {
            res.push_back(freq[i].second);
        }

        return res;
        
    }
};
