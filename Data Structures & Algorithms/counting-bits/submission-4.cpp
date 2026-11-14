class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);

        for(int i{}; i <= n; ++i) {
            res[i] = countOnes(i);
        }

        return res;
    }

    int countOnes(int n) {
        int res{};
        while(n) {
            n &= (n - 1);
            ++res;
        }

        return res;
    }
};
