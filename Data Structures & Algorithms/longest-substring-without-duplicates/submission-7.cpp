class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int longestSubstring = 0;
        // int strSz = s.size();
        // if(strSz == 0) {
        //     return longestSubstring;
        // }

        // if(strSz == 1) {
        //     return 1;
        // }
        // int currLength = 0;
        // int left = 0;
        // unordered_map<char, int> substring;
        // for(int i = 0; i < strSz; i++) {
        //     auto it = substring.find(s[i]);
        //     if(it != substring.end()) {
        //         substring.clear();
        //         longestSubstring = max(longestSubstring, currLength);
        //         substring.emplace(s[i], i);
        //         currLength = 1;
        //         continue;
        //     }
        //     substring.emplace(s[i], i);
        //     currLength++;
        // }
        // return max(longestSubstring, currLength);
        // //

        vector<int> lastseen(256, -1); //last index seen for each printable
        // ascii char, initialized to -1 to guarantee storage on the first
        // pass

        int longestSubstring = 0;
        int leftIdx = 0;
        int strSz = s.size();

        for(int i = 0; i<strSz; i++) {
            unsigned char currChar = s[i]; //curr char
            if( lastseen[currChar] >= leftIdx)
                leftIdx = lastseen[currChar] + 1; // if a duplicate is found within the window, move the left pointer to 1 position past the 
                // occurence of the character
            lastseen[currChar] = i;
            longestSubstring = max(longestSubstring, i - leftIdx + 1);
        }

        return longestSubstring;
    }
};
