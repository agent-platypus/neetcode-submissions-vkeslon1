class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freq;
        vector<vector<string>> res;

        for(const string& curr: strs) {
            string s = curr;
            sort(s.begin(), s.end());
            freq[s].push_back(curr);
        }

        for(auto& i: freq) {
            res.push_back(i.second);
        }

        return res;
       
    }
};
