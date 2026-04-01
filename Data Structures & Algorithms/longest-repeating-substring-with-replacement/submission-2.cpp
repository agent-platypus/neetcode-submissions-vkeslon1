class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        unordered_map<char, int> freq;
        int maxf = 0;
        int res = 0;

        for(int r = 0; r < s.size(); r++) {
            freq[s[r]]++;
            maxf = max(maxf, freq[s[r]]);

            while((r - left + 1) - maxf > k) {
                freq[s[left]]--;
                left++;
            }
            res = max(res, r - left + 1);
        }
        
        return res;

        
    }
};
