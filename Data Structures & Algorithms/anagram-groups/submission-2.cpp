class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map<string, vector<string>> freq;
        // vector<vector<string>> res;

        // for(const string& curr: strs) {
        //     string s = curr;
        //     sort(s.begin(), s.end());
        //     freq[s].push_back(curr);
        // }

        // for(auto& i: freq) {
        //     res.push_back(i.second);
        // }

        // return res;
        unordered_map<string, vector<string>> res;
        for (const auto& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};
