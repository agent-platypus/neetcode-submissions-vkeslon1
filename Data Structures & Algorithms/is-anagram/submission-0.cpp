class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> freq;
        for(const auto& ch: s) {
            freq[ch]++;
        }

        for(const auto& ch: t) {
            freq[ch]--;
        }

        for(auto it: freq) {
            if (it.second) {
                return false;
            }
        }

        return true;
    }
};
