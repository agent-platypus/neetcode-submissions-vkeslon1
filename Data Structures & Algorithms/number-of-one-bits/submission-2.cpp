class Solution {
public:
    int hammingWeight(uint32_t n) {
        int numOnes = 0;
        for(int i{}; i < 32; ++i) {
            int checkOne = (n >> i) & 1;
            numOnes += checkOne;
        }

        return numOnes;
    }
};
