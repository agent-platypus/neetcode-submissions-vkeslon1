class Solution {
public:
    int characterReplacement(string s, int k) {
        int left{};
        int right{};

        int maxLen{};
        vector<int> freqMap(26);

        int maxFreq{};
        while(right < s.size()) {
            char ch = s[right];
            ++freqMap[ch - 'A'];
            maxFreq = max(maxFreq, freqMap[ch - 'A']);
            int currWindow = right - left + 1;

            if (currWindow - maxFreq <= k) {
                maxLen = max(maxLen, currWindow);
            }
            else {
                --freqMap[s[left] - 'A'];
                ++left;
            }
            ++right;
        }

        return maxLen;
    }
};
