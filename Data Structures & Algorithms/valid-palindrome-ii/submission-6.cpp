#include <string_view>
#include <print>

class Solution {
public:
    bool validPalindrome(string s) {

        string_view view{s};
        size_t left{};
        size_t right{s.size() - 1};

        while (left < right) {
            if (s[left] != s[right]) {
                return isPalindrome(view.substr(left + 1, right - left ) ) || isPalindrome(view.substr(left, right - left ) );
            }
            ++left;
            --right;
        }

        return true;
        

    }

    bool isPalindrome(string_view s) {
        size_t left{};
        size_t right{s.size() - 1};
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