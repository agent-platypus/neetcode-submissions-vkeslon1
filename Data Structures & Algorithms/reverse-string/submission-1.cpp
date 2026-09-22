class Solution {
public:
    void reverseString(vector<char>& s) {
        int left{};

        int right = s.size() - 1;

        for(int i{}; i < (s.size() >> 1); ++i) {
            char tmp{s[i]};
            s[i] = s[right];
            s[right] = tmp;
            --right;
        }

    }
};