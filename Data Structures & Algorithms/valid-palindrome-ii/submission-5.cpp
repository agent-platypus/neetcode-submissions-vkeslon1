class Solution {
public:
    bool validPalindrome(string s) {
        int right = s.length() - 1;
        int left = 0;

        while(left < right) {
            if (s[right] != s[left]) {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;

        // when iterating through the string and a mismatch in character 
        // between the left and right pointer is detected, check if incrementing the left pointer
        // or decrementing the right pointer results in a match in character 
    }

    bool isPalindrome(const string& s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;

    }
};