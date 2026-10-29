#include <print>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // auto printFreq = [](span<const int> s1_freq, span<const int> s2_freq) {
        //     print("start of print\n");
        //     for(int i{}; i < 26; ++i) {

        //         print("s1 char = {}, freq = {} ||", static_cast<char>(i + 'a'), s1_freq[i]);
        //         print("s2 char = {}, freq = {} ||", static_cast<char>(i + 'a'), s2_freq[i]);
        //     }
        //     print("end of print\n");
        // };

        vector<int> s1_freq(26);
        vector<int> s2_freq(26);

        if (s1.length() > s2.length()) {
            return false;
        }

        for(char c: s1) {
            s1_freq[c - 'a']++;
        }

        for(int i{}; i < s1.length(); ++i) {
            char currChar = s2[i];
            s2_freq[currChar - 'a']++;
        }

        int matches = 0;
        for(int j{}; j < 26; ++j) {
            if (s2_freq[j] == s1_freq[j]) {
                matches++;
            }
        }
        // abc


        //  lecabee
        //  ^ ^ 
        //   ^ ^ 
        //
        //
        //

        // printFreq(s1_freq, s2_freq);
        int left = 0;

        for(int charInS2 = s1.length(); charInS2 < s2.length(); ++charInS2) {
            if (matches == 26) {
                return true;
            }

            //shift the window 1 character to the right
            int currRChar = s2[charInS2];
            int currRIdx = currRChar - 'a';
            s2_freq[currRIdx]++;

            // after shifting the right pointer 1 to the right, 
            // the window may increase an existing character
            // or add in a new character to the map 
            if (s2_freq[currRIdx] == s1_freq[currRIdx]) {
                ++matches;
            }
            else if (s1_freq[currRIdx] == s2_freq[currRIdx] - 1) {
                --matches;
            }

            int currLChar = s2[left];
            int currLIdx = currLChar - 'a';

            --s2_freq[currLIdx];

            if (s2_freq[currLIdx] == s1_freq[currLIdx]) {
                ++matches;
            }
            else if (s2_freq[currLIdx] + 1 == s1_freq[currLIdx]) {
                --matches;
            }

            left++;
            // printFreq(s1_freq, s2_freq);
        }

        // print("matches = {}\n", matches);
        return matches == 26;
    }
};
