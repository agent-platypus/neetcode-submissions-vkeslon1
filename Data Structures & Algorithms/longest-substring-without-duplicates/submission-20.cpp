#include <print>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left{};
        int right{};

        int maxLen{};

        // bbbbb

        // b = 2

        // right = 1
        // left = 0 

        // zxyzxyz 

        // z 1
        // x 1
        // y 1
        
        // left = 0 -> 3
        // right = 3
        // len = 3
        
        unordered_map<char, int> uniqueOccur;
        while(right < s.size()) {
            char currChar = s[right];
            auto it = uniqueOccur.find(currChar);


            if (it != uniqueOccur.end()) {
                left = max(uniqueOccur[currChar] + 1, left);
            }
            uniqueOccur[currChar] = right;
            maxLen = max(maxLen, right - left + 1);
            ++right;
        }
        return maxLen;
    }
};
