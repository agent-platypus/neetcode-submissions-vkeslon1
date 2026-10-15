#include <string_view>
#include <print>

class Solution {
public:
    bool validPalindrome(string s) {

        size_t left{};
        size_t right{s.size() - 1};

        while (left < right) {
            if (s[left] != s[right]) {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            ++left;
            --right;
        }

        return true;
        

    }

    bool isPalindrome(const string& s, size_t left, size_t right) {
        while(left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }

        return true;
    }
};