class Solution {
public:
    void reverseString(vector<char>& s) {

        int right = s.size() - 1;
        for(int left = 0; left < (s.size() / 2); left++) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            right--;
        }

    }
};