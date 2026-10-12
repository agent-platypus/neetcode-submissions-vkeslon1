#include <cctype>
#include <print>

class Solution {
public:
    bool isPalindrome(string s) {

        int fwdPtr{};
        int bwdPtr{static_cast<int>(s.length() - 1)};

        while(fwdPtr < bwdPtr) {

            while(fwdPtr < bwdPtr && !validChar( s[fwdPtr] ) ) {
                ++fwdPtr;
            }
            while(fwdPtr < bwdPtr && !validChar(s[bwdPtr])) {
                --bwdPtr;
            }

            if (tolower(s[fwdPtr]) != tolower(s[bwdPtr])) {
                return false;
            }
            ++fwdPtr;
            --bwdPtr;
        }

        return true;
    }

    bool validChar(char s) {
        
        // return ( s >= 'a' && s <= 'z' || s >= 'A' && s <= 'Z' || s >= '0' && s <= '9');
        return !((s < 'a' || s > 'z') && (s < 'A' || s > 'Z') && (s < '0' || s > '9'));
    }
};
