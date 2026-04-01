class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        vector<pair<int, int>> freq_pairs;
        for(auto it: freq) {
            freq_pairs.push_back({it.first, it.second});
        }

        sort(freq_pairs.begin(), freq_pairs.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second > b.second;
        });


        for(int i = 0; i < k; i++) {
            res.push_back(freq_pairs[i].first);
        }
        
        return res;
    }
};
