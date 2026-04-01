class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> curr_string;
        int left = 0;
        int longestlen = 0;

        for(int right = 0; right < s.size(); right++) {
            if(curr_string.find(s[right]) != curr_string.end()) {
                left = max(curr_string[s[right]] + 1, left);
            }
            curr_string[s[right]] = right;
            longestlen = max(longestlen, right - left + 1);
        }

        return longestlen;
    }
};
